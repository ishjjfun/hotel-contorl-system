#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"

//relay
int fd_relay;
#define RELAY_DEVICE_FILENAME "/dev/relay"
#define RELAY_ON 0
#define RELAY_OFF 1
//rfid
volatile unsigned int cardid ;         //卡片的ID
static struct timeval timeout;         //串口
#define DEV_PATH   "/dev/ttySAC1"      //设备定义
//#define DEV_PATH   "/dev/s3c2410_serial1"      //设备定义
//function of rfid

//初始化rfid
void init_tty(int fd_id)
{

    //声明设置串口的结构体ui->setupUi(this);
    struct termios termios_new;
    //先清空该结构体
    bzero( &termios_new, sizeof(termios_new));
    //	cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。
    cfmakeraw(&termios_new);
    //设置波特率
    termios_new.c_cflag=(B9600);
    //cfsetispeed(&termios_new, B9600);
    //cfsetospeed(&termios_new, B9600);
    //CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项。
    termios_new.c_cflag |= CLOCAL | CREAD;
    //通过掩码设置数据位为8位
    termios_new.c_cflag &= ~CSIZE;
    termios_new.c_cflag |= CS8;
    //设置无奇偶校验
    termios_new.c_cflag &= ~PARENB;
    //一位停止位
    termios_new.c_cflag &= ~CSTOPB;
    tcflush(fd_id,TCIFLUSH);
    // 可设置接收字符和等待时间，无特殊要求可以将其设置为0
    termios_new.c_cc[VTIME] = 10;
    termios_new.c_cc[VMIN] = 1;
    // 用于清空输入/输出缓冲区
    tcflush (fd_id, TCIFLUSH);//处理未接收的信息
    //完成配置后，可以使用以下函数激活串口设置
    if(tcsetattr(fd_id,TCSANOW,&termios_new) )
        printf("<0>""Setting the serial1 failed!\n");
}


//计算校验和
unsigned char CalBCC(unsigned char *buf, int n)
{
    int i;
    unsigned char bcc=0;
    for(i = 0; i < n; i++)
    {
        bcc ^= *(buf+i);
    }
    return (~bcc);
}


int PiccRequest(int fd_id)
{
    unsigned char WBuf[128], RBuf[128];
    int  ret, i,len;
    fd_set rdfd;

    memset(WBuf, 0, 128);
    memset(RBuf,0,128);
    WBuf[0] = 0x07;	//帧长= 7 Byte
    WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x01
    WBuf[2] = 0x41;	//命令= 'C'ui->setupUi(this);
    WBuf[3] = 0x01;	//信息长度= 0
    WBuf[4] = 0x52;	//请求模式:  ALL=0x52
    WBuf[5] = CalBCC(WBuf, WBuf[0]-2);		//校验和
    WBuf[6] = 0x03; 	//结束标志

    FD_ZERO(&rdfd);
    FD_SET(fd_id,&rdfd);
    tcflush (fd_id, TCIFLUSH);
    ret = write(fd_id, WBuf, 7);
    ret = select(fd_id + 1,&rdfd, NULL,NULL,&timeout);
    switch(ret)
    {
        case -1:
            perror("select error\n");
            break;
        case  0:
            //printf("<0>""Request timed out.\n");
            break;
        default:
            usleep(10000);
            ret = read(fd_id, RBuf, 1);
            //ret = read(fd_id, RBuf, 8);
            len = ret;
            ret = read(fd_id, RBuf+len, 1);
            len +=ret;
            if (len < 0)
            {
                //printf("len = %d, %m-----------------------------------------------\n", len, errno);
                break;
            }
            if (RBuf[2] == 0x00)	 	//应答帧状态部分为0 则请求成功
            {
                return 0;
            }
            break;
    }
    return -1;
}


//防碰撞，获取范围内最大ID
int PiccAnticoll(int fd_id)
{
    unsigned char WBuf[128], RBuf[128];
    int ret, i,len;
    fd_set rdfd;;
    memset(WBuf, 0, 128);
    memset(RBuf,0,128);
    WBuf[0] = 0x08;	//帧长= 8 Byte
    WBuf[1] = 0x02;	//包号= 0 , 命令类型= 0x01
    WBuf[2] = 0x42;	//命令= 'B'
    WBuf[3] = 0x02;	//信息长度= 2
    WBuf[4] = 0x93;	//防碰撞0x93 --一级防碰撞
    WBuf[5] = 0x00;	//位计数0
    WBuf[6] = CalBCC(WBuf, WBuf[0]-2);		//校验和
    WBuf[7] = 0x03; 	//结束标志
    tcflush (fd_id, TCIFLUSH);
    FD_ZERO(&rdfd);
    FD_SET(fd_id,&rdfd);
    write(fd_id, WBuf, 8);
    ret = select(fd_id + 1,&rdfd, NULL,NULL,&timeout);
    switch(ret)
    {
        case -1:
            perror("select error\n");
            break;
        case  0:
            perror("Timeout:");
            break;
        default:
            usleep(10000);
            //for();
                        //ret = read(fd, RBuf, 10);
            ret = read(fd_id, RBuf, 1);
                        len = ret;
                        ret = read(fd_id, RBuf+len, 8);
                        len +=ret;

            if (len < 0)
            {
                //printf("--------------------------------------------------------len = %d, %m\n", len, errno);
                break;
            }
            if (RBuf[2] == 0x00) //应答帧状态部分为0 则获取ID 成功
            {
                cardid = (RBuf[4]<<24) | (RBuf[5]<<16) | (RBuf[6]<<8) | RBuf[7];
                return 0;
            }
    }
    return -1;
}

void MainWindow::on_pushButton_clicked()
{
    int ret, i;
        int fd;

        fd = open(DEV_PATH, O_RDWR | O_NOCTTY | O_NONBLOCK);
        //fd = open(DEV_PATH, O_RDWR);
        if (fd < 0)
        {
            printf("<0>""---------------------------------------------open is error\n");
            fprintf(stderr, "Open Gec6818_ttySAC1 fail!\n");
           // return -1;
        }
        while(1)
        {
            sleep(1);
            /*初始化串口*/
            init_tty(fd);
            timeout.tv_sec = 10;
            timeout.tv_usec = 0;
            /*请求天线范围的卡*/
            if ( PiccRequest(fd) )
            {
                printf("<0>""-----------------------------------The request failed!\n");
                continue;
            }
            /*进行防碰撞，获取天线范围内最大的ID*/
            if( PiccAnticoll(fd) )
            {
                printf("<0>""----------------------------------Couldn't get card-id!\n");
                continue;
            }
            printf("<0>""----------------card ID = %x-------------\n", cardid);
            if (cardid == 0x5982933e)
            {
                printf("success");
                ioctl(fd_relay, RELAY_ON, 0);
                printf("relay on");
                break;
            }
            cardid = 0;
        }
    home *f = new home(this);
    f->show();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fd_relay = open(RELAY_DEVICE_FILENAME, O_RDWR);
    ioctl(fd_relay, RELAY_OFF, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
