#include "equipmentcontrol.h"
#include "ui_equipmentcontrol.h"
//bujindianji
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
//zhiliudianji
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TEST_MAGIC1111 'x'
#define TEST_MAGIC 'x'
#define TEST_MAX_NR 2

#define PATH  	"/dev/dc_motor"                 //绝对路径
int count;
int fd_stempmotor;
int fd_motor;
int open_or_close;
int initwendu;
int fd_light;
int fd_tem;
int count1;

equipmentcontrol::equipmentcontrol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipmentcontrol)
{
    ui->setupUi(this);
     fd_stempmotor=::open("/dev/stepmotor", O_RDWR);
     fd_motor = ::open(PATH, O_RDWR);
     fd_light=::open("/dev/light_drv", O_RDWR);
     fd_tem = ::open("/dev/humidity", O_RDWR);
     count = 0;
    count1 = 0;
     open_or_close = 0;
     initwendu = 25;
     ui->label_3->setText(QString("%1").arg(count1));
}

equipmentcontrol::~equipmentcontrol()
{
    delete ui;
}

void equipmentcontrol::on_pushButton_5_clicked()
{
    close();
}

//left
void equipmentcontrol::on_pushButton_6_clicked()
{
    fd_stempmotor=::open("/dev/stepmotor", O_RDWR);
    for (int j=0; j<20; j++ )
    :: ioctl(fd_stempmotor,3,20);
    if (count1>0)
    {
    count1 = count1-1;
    }
    ui->label_3->setText(QString("%1").arg(count1));
}

//right
void equipmentcontrol::on_pushButton_7_clicked()
{
    fd_stempmotor=::open("/dev/stepmotor", O_RDWR);
    for (int j=0; j<20; j++ )
    :: ioctl(fd_stempmotor,1,20);
    if (count1<10)
    {
    count1 = count1+1;
    }
    ui->label_3->setText(QString("%1").arg(count1));
}

//open/close airconditional
void equipmentcontrol::on_pushButton_2_clicked()
{
    fd_motor = ::open(PATH, O_RDWR);
  if(open_or_close == 0)
   {
      ui->label->setText(QString("%1℃").arg(initwendu));
//      printf("open_or_close=%d",open_or_close);
//      printf( "?????\n");
       ::ioctl(fd_motor, 4, 0);
       open_or_close=1;
//      printf("open_or_close=%d",open_or_close);
//       printf( "?????\n");
}
  else if (open_or_close == 1){
      ui->label->setText(QString(" "));
      ::ioctl(fd_motor, 0, 0);
     open_or_close=0;
     ::close(fd_motor);
 }
}

//+wendu
void equipmentcontrol::on_pushButton_3_clicked()
{
    fd_motor = ::open(PATH, O_RDWR);
    if (open_or_close == 1 && initwendu<30)
    {
        initwendu = initwendu+1;
    }
    ui->label->setText(QString("%1℃").arg(initwendu));
    ::ioctl(fd_motor, 4, 0);
}

//-wendu
void equipmentcontrol::on_pushButton_4_clicked()
{
    fd_motor = ::open(PATH, O_RDWR);
    if (open_or_close == 1 && initwendu>16)
    {
        initwendu = initwendu-1;
    }
    ui->label->setText(QString("%1℃").arg(initwendu));
    ::ioctl(fd_motor, 1, 0);
}

//zhinengtiaokong
void equipmentcontrol::on_pushButton_8_clicked()
{
    fd_stempmotor=::open("/dev/stepmotor", O_RDWR);
    fd_motor = ::open(PATH, O_RDWR);
    fd_light=::open("/dev/light_drv", O_RDWR);
    fd_tem = ::open("/dev/humidity", O_RDWR);
        timer=new QTimer();
        timer1=new QTimer();
        timer2=new QTimer();
        timer3=new QTimer();

        timer->start(3000);
        timer1->start(6000);
        timer2->start(3000);
        timer3->start(3000);

        connect(timer,SIGNAL(timeout()),this,SLOT(myTimerOut()));//延时启动
        connect(timer1,SIGNAL(timeout()),this,SLOT(myTimerOut1()));//温度
        connect(timer2,SIGNAL(timeout()),this,SLOT(myTimerOut2()));//光照
        connect(timer3,SIGNAL(timeout()),this,SLOT(myTimerOut3()));//光照
}

void equipmentcontrol::myTimerOut(){
    fd_tem = ::open("/dev/humidity", O_RDWR);
    ret = read(fd_tem,&temperature,sizeof( temperature ));
    //温度输出
    tempz = (temperature & 0x0000ff00)>>8;
    tempx = (temperature & 0x000000ff);
    printf("temp = %d.%d\n",tempz,tempx);
    timer1=new QTimer();
    ui->label->setText(QString("%1").arg(tempz));
}

//wendukongzhi
void equipmentcontrol::myTimerOut1(){
//    fd_motor = ::open(PATH, O_RDWR);
    if(tempz  >=25){
     :: ioctl(fd_motor,1,0);
    }
    else if(tempz  <=25){
    :: ioctl(fd_motor,4,0);
    }
}

//模拟光照
void equipmentcontrol::myTimerOut2(){
    fd_light=::open("/dev/light_drv", O_RDWR);
    ret1 = read(fd_light,&light_value,2);
    printf("light_value = %d \n",light_value);
}

void equipmentcontrol::myTimerOut3(){
    fd_stempmotor=::open("/dev/stepmotor", O_RDWR);
    if(light_value<50){
      count = 0;
      ui->label_3->setText(QString("%1").arg(count));
      ::ioctl(fd_stempmotor, 3, 50);
    }
    if(light_value>50&&light_value<100){
      count = 2;
      ui->label_3->setText(QString("%1").arg(count));
      ::ioctl(fd_stempmotor, 1, 50);
    }
    if(light_value>100&&light_value<200){
      count = 4;
      ui->label_3->setText(QString("%1").arg(count));
      ::ioctl(fd_stempmotor, 1, 50);
    }
    if(light_value>200&&light_value<300){
      count = 6;
      ui->label_3->setText(QString("%1").arg(count));
      ::ioctl(fd_stempmotor, 1, 50);
    }
    if(light_value>300&&light_value<400){
      count = 8;
      ui->label_3->setText(QString("%1").arg(count));
      ::ioctl(fd_stempmotor, 1, 50);
    }
    if(light_value>400){
        count = 10;
        ui->label_3->setText(QString("%1").arg(count));
        ::ioctl(fd_stempmotor, 1, 50);
      ::ioctl(fd_stempmotor, 1, 50);
    }
}
#define TEST_MAGIC1111 'x'
#define TEST_MAGIC 'x'
#define TEST_MAX_NR 2
//关闭智能调控
void equipmentcontrol::on_pushButton_9_clicked()
{
    timer->stop();
    timer1->stop();
    timer2->stop();
    ::ioctl(fd_motor, 0, 0);
    ::ioctl(fd_stempmotor, 0, 0);
    ::close(fd_motor);
    ::close(fd_stempmotor);
    ::close(fd_tem);
    ::close(fd_light);
}
