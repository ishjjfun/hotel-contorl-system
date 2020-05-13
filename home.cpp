#include "home.h"
#include "ui_home.h"
#include "modelcontrol.h"
#include "equipmentcontrol.h"
#include "call1.h"

#include "call.h"
#include "ui_call.h"
#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <termios.h>
#include <netdb.h>
#include <QTime>
#include <QTimer>
#include<iostream>
#define  BUZZER_IOCTL_SET_FREQ 1
#define  BUZZER_IOCTL_STOP 0
using namespace std;
#include <sys/ioctl.h>

int buzzer_fd;
int open_or_close;

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    unsigned long freq = 2000;
    open_or_close = 0;
    buzzer_fd =:: open("/dev/pwm",O_RDWR);
     Init();
}

home::~home()
{
    delete ui;
}

//model
void home::on_pushButton_clicked()
{
    modelcontrol *f = new modelcontrol(this);
    f->show();
}

//equipment
void home::on_pushButton_2_clicked()
{
    equipmentcontrol *f = new equipmentcontrol(this);
    f->show();
}

//call
void home::on_pushButton_3_clicked()
{
    call *f = new call(this);
    f->show();
}


void home::Init(){
    manager = new QNetworkAccessManager(this);
}


void home::send_message(QString test ){
    QNetworkRequest request;
    QUrl url;
    QString pwd="1008611";
     url.setUrl("http://123.206.227.102/test/pwd.php?pwd="+test);
    request.setUrl(url);
    reply = manager->get(request);
    connect(reply,SIGNAL(readyRead()),
       this,SLOT(doProcessReadyRead()));
    connect(reply,SIGNAL(error(QNetworkReply::NetworkError)),
        this,SLOT(doProcessError(QNetworkReply::NetworkError)));
    connect(reply,SIGNAL(finished()),
        this,SLOT(doProcessFinished()));
}

//sos
void home::on_pushButton_4_clicked()
{
//    QString pwd = "2";
//    send_message(pwd);
    if(open_or_close == 0){
        QString pwd = "2";
        send_message(pwd);
        open_or_close = 1;
        ::ioctl(buzzer_fd , BUZZER_IOCTL_SET_FREQ , freq);
    }
    else if(open_or_close == 1){
        open_or_close = 0;
        ::ioctl(buzzer_fd , BUZZER_IOCTL_STOP , freq);
    }
}

