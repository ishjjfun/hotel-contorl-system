/********************************************************************************
** Form generated from reading UI file 'call.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALL_H
#define UI_CALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_call
{
public:
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *call)
    {
        if (call->objectName().isEmpty())
            call->setObjectName(QStringLiteral("call"));
        call->resize(947, 542);
        label_2 = new QLabel(call);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 10, 191, 81));
        label_2->setStyleSheet(QLatin1String("font: 75 26pt \"Century Schoolbook L\";\n"
""));
        label_5 = new QLabel(call);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 350, 121, 61));
        label_5->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        label_6 = new QLabel(call);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 350, 111, 61));
        label_6->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        pushButton_5 = new QPushButton(call);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 20, 61, 61));
        pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/pic/xiangzuo (1).png);"));
        pushButton_3 = new QPushButton(call);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 160, 171, 181));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/pic/-.png);"));
        pushButton = new QPushButton(call);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 160, 171, 171));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/pic/Call/fuwuyuan.png);"));

        retranslateUi(call);

        QMetaObject::connectSlotsByName(call);
    } // setupUi

    void retranslateUi(QDialog *call)
    {
        call->setWindowTitle(QApplication::translate("call", "Dialog", 0));
        label_2->setText(QApplication::translate("call", "\345\221\274\345\217\253\346\234\215\345\212\241", 0));
        label_5->setText(QApplication::translate("call", "\345\221\274\345\217\253\345\211\215\345\217\260", 0));
        label_6->setText(QApplication::translate("call", "\345\207\206\345\244\207\351\200\200\346\210\277", 0));
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class call: public Ui_call {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALL_H
