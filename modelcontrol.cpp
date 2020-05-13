#include "modelcontrol.h"
#include "ui_modelcontrol.h"


#define IOCTL_LED_ON    0
#define IOCTL_LED_OFF   1

#define TEST_MAGIC1111 'x'
#define TEST_MAGIC 'x'
#define TEST_MAX_NR 2

#define  BUZZER_IOCTL_SET_FREQ 1
#define  BUZZER_IOCTL_STOP 0

#define LED1 _IO(TEST_MAGIC, 0)
#define LED2 _IO(TEST_MAGIC, 1)
#define LED3 _IO(TEST_MAGIC, 2)
#define LED4 _IO(TEST_MAGIC, 3)

#define  BUZZER_IOCTL_SET_FREQ 1
#define  BUZZER_IOCTL_STOP 0

int fd_flame = 0;
int flame_flag;
int ret3 ;
int buzzer_fd;
int fd;

int a = flame_flag;
unsigned long freq = 2000;

modelcontrol::modelcontrol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modelcontrol)
{
    ui->setupUi(this);
    fd = ::open("/dev/Led", O_RDWR);
    fd_flame = ::open("/dev/flame_drv", O_RDWR);
    buzzer_fd =:: open("/dev/pwm",O_RDWR);
}

modelcontrol::~modelcontrol()
{
    delete ui;
}

void modelcontrol::on_pushButton_4_clicked()
{
    close();
}
//read model
void modelcontrol::on_pushButton_clicked()
{
        ::ioctl(fd,LED1,IOCTL_LED_ON);
        ::ioctl(fd,LED2,IOCTL_LED_OFF);
        ::ioctl(fd,LED3,IOCTL_LED_OFF);
        ::ioctl(fd,LED4,IOCTL_LED_OFF);
}
//video model
void modelcontrol::on_pushButton_2_clicked()
{
    ::ioctl(fd,LED1,IOCTL_LED_OFF);
    ::ioctl(fd,LED2,IOCTL_LED_ON);
    ::ioctl(fd,LED3,IOCTL_LED_ON);
    ::ioctl(fd,LED4,IOCTL_LED_OFF);
}
//sleep model
void modelcontrol::on_pushButton_3_clicked()
{
    ::ioctl(fd,LED1,IOCTL_LED_OFF);
    ::ioctl(fd,LED2,IOCTL_LED_OFF);
    ::ioctl(fd,LED3,IOCTL_LED_OFF);
    ::ioctl(fd,LED4,IOCTL_LED_OFF);
    timer=new QTimer();
     timer1=new QTimer();

      timer->start(3000);
      timer1->start(3001);

     connect(timer,SIGNAL(timeout()),this,SLOT(myTimerOut()));//延时启动
     connect(timer1,SIGNAL(timeout()),this,SLOT(myTimerOut1()));//延时启动
}

//WC
void modelcontrol::on_pushButton_5_clicked()
{
    ::ioctl(fd,LED1,IOCTL_LED_OFF);
    ::ioctl(fd,LED2,IOCTL_LED_OFF);
    ::ioctl(fd,LED3,IOCTL_LED_ON);
    ::ioctl(fd,LED4,IOCTL_LED_ON);
}

//
void modelcontrol::on_pushButton_6_clicked()
{
    ::ioctl(fd,LED1,IOCTL_LED_ON);
    ::ioctl(fd,LED2,IOCTL_LED_ON);
    ::ioctl(fd,LED3,IOCTL_LED_ON);
    ::ioctl(fd,LED4,IOCTL_LED_ON);
}

void modelcontrol::myTimerOut(){
        ret3 = read(fd_flame,&flame_flag,sizeof(flame_flag));
        printf("flame_flag = %d \n",flame_flag);
        printf("!!!fd_flame= %d \n",a);
}

void modelcontrol::myTimerOut1(){
        if(flame_flag==0 ){
            printf("baojingle");
            ::ioctl(buzzer_fd , BUZZER_IOCTL_SET_FREQ , freq);
            sleep(2);
            ::ioctl(buzzer_fd , BUZZER_IOCTL_STOP , freq);}
}
