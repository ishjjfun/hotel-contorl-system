#ifndef MODELCONTROL_H
#define MODELCONTROL_H

#include <QDialog>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <poll.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <limits.h>
#include <QTime>
#include <QTimer>

namespace Ui {
class modelcontrol;
}

class modelcontrol : public QDialog
{
    Q_OBJECT

public:
    explicit modelcontrol(QWidget *parent = 0);
    int ret3;
            QTimer *timer;
                QTimer *timer1;
    ~modelcontrol();

public slots:
    void myTimerOut();
        void myTimerOut1();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::modelcontrol *ui;
    int fd;
    int fd_flame = 0;
        int flame_flag;
        int buzzer_fd;
};

#endif // MODELCONTROL_H
