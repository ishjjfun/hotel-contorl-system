#ifndef EQUIPMENTCONTROL_H
#define EQUIPMENTCONTROL_H

#include <QDialog>
#include <QWidget>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <QString>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <QTime>
#include <QTimer>
#include <QMainWindow>
#include <poll.h>

namespace Ui {
class equipmentcontrol;
}

class equipmentcontrol : public QDialog
{
    Q_OBJECT

public:
    explicit equipmentcontrol(QWidget *parent = 0);
    ~equipmentcontrol();
    QTimer *timer;
        QTimer *timer1;
        QTimer *timer2;
        QTimer *timer3;
//        QTimer *timer4;
//        QTimer *timer5;
        unsigned short tempz=0;
        unsigned short tempx=0;
        unsigned long temperature=0;
        short light_value=0;
        int ret;
        int ret1;
        int ret3;

public slots:
    void myTimerOut();
    void myTimerOut1();
    void myTimerOut2();
    void myTimerOut3();


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::equipmentcontrol *ui;
    int count;
    int count1;
     int fd_tem;
     int fd_stempmotor;
     int fd_light;
     int fd_motor;
};

#endif // EQUIPMENTCONTROL_H
