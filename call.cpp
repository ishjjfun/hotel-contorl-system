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


call::call(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::call)
{
    ui->setupUi(this);
    Init();
}

call::~call()
{
    delete ui;
}

void call::on_pushButton_5_clicked()
{
    close();
}

void call::Init(){
    manager = new QNetworkAccessManager(this);
}


void call::send_message(QString test ){
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

void call::on_pushButton_clicked()
{
    QString pwd = "3";
    send_message(pwd);
}

void call::on_pushButton_3_clicked()
{
    QString pwd = "0";
     send_message(pwd);
}
