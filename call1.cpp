#include "call1.h"
#include "ui_call.h"

call::call(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::call)
{
    ui->setupUi(this);
}

call::~call()
{
    delete ui;
}

void call::on_pushButton_5_clicked()
{
    close();
}
