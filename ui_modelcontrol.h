/********************************************************************************
** Form generated from reading UI file 'modelcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELCONTROL_H
#define UI_MODELCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_modelcontrol
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *modelcontrol)
    {
        if (modelcontrol->objectName().isEmpty())
            modelcontrol->setObjectName(QStringLiteral("modelcontrol"));
        modelcontrol->resize(947, 542);
        pushButton = new QPushButton(modelcontrol);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 100, 141, 111));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/pic/ModelControl/yuedu.png);"));
        pushButton_2 = new QPushButton(modelcontrol);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 100, 141, 111));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/pic/ModelControl/huabankaobei.png);"));
        pushButton_3 = new QPushButton(modelcontrol);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 90, 141, 121));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/pic/ModelControl/shuimianjianceqitang.png);"));
        label_2 = new QLabel(modelcontrol);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 30, 211, 71));
        label_2->setStyleSheet(QLatin1String("font: 75 26pt \"Century Schoolbook L\";\n"
""));
        pushButton_4 = new QPushButton(modelcontrol);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 30, 61, 71));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/pic/xiangzuo (1).png);"));
        label_3 = new QLabel(modelcontrol);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 210, 121, 61));
        label_3->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        label_4 = new QLabel(modelcontrol);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 210, 131, 61));
        label_4->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        label_5 = new QLabel(modelcontrol);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(640, 210, 111, 61));
        label_5->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        pushButton_5 = new QPushButton(modelcontrol);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 200, 151, 141));
        pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/pic/cesuo.png);"));
        pushButton_6 = new QPushButton(modelcontrol);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(470, 200, 131, 151));
        pushButton_6->setStyleSheet(QStringLiteral("border-image: url(:/pic/keting.png);"));
        label_6 = new QLabel(modelcontrol);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 340, 121, 61));
        label_6->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        label_7 = new QLabel(modelcontrol);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 340, 121, 61));
        label_7->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));

        retranslateUi(modelcontrol);

        QMetaObject::connectSlotsByName(modelcontrol);
    } // setupUi

    void retranslateUi(QDialog *modelcontrol)
    {
        modelcontrol->setWindowTitle(QApplication::translate("modelcontrol", "Dialog", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_2->setText(QApplication::translate("modelcontrol", "\346\250\241\345\274\217\351\200\211\346\213\251", 0));
        pushButton_4->setText(QString());
        label_3->setText(QApplication::translate("modelcontrol", "\351\230\205\350\257\273\346\250\241\345\274\217", 0));
        label_4->setText(QApplication::translate("modelcontrol", "\350\247\202\345\275\261\346\250\241\345\274\217", 0));
        label_5->setText(QApplication::translate("modelcontrol", "\347\235\241\347\234\240\346\250\241\345\274\217", 0));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        label_6->setText(QApplication::translate("modelcontrol", "\345\216\225\346\211\200\346\250\241\345\274\217", 0));
        label_7->setText(QApplication::translate("modelcontrol", "\345\244\247\347\201\257\346\250\241\345\274\217", 0));
    } // retranslateUi

};

namespace Ui {
    class modelcontrol: public Ui_modelcontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELCONTROL_H
