#ifndef CALL_H
#define CALL_H

#include <QWidget>

namespace Ui {
class call;
}

class call : public QWidget
{
    Q_OBJECT

public:
    explicit call(QWidget *parent = 0);
    ~call();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::call *ui;
};

#endif // CALL_H
