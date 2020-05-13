#ifndef CALL_H
#define CALL_H

#include <QWidget>
#include<QThread>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QDialog>

namespace Ui {
class call;
}

class call : public QDialog
{
    Q_OBJECT

public:
    explicit call(QWidget *parent = 0);
    ~call();

public slots:

  void  send_message(QString test);



private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::call *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    void Init();
};

#endif // CALL_H
