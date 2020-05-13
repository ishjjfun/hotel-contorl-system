/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QLabel *label_6;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QPushButton *pushButton;

    void setupUi(QDialog *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QStringLiteral("home"));
        home->resize(947, 542);
        label_6 = new QLabel(home);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 310, 121, 51));
        label_6->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        label_5 = new QLabel(home);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(620, 310, 111, 51));
        label_5->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        pushButton_3 = new QPushButton(home);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 150, 141, 141));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/pic/Call/dianhua.png);"));
        label_3 = new QLabel(home);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 310, 121, 51));
        label_3->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        pushButton_2 = new QPushButton(home);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 160, 151, 141));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/pic/EquipmentControl/shebei.png);"));
        label_2 = new QLabel(home);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 10, 441, 121));
        label_2->setStyleSheet(QLatin1String("font: 75 36pt \"Century Schoolbook L\";\n"
""));
        pushButton_4 = new QPushButton(home);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 150, 131, 141));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/pic/SOS/sos.png);"));
        label_4 = new QLabel(home);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 310, 121, 51));
        label_4->setStyleSheet(QLatin1String("font: 75 15pt \"Century Schoolbook L\";\n"
""));
        pushButton = new QPushButton(home);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 150, 131, 141));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/pic/ModelControl/model.png);\n"
""));

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QDialog *home)
    {
        home->setWindowTitle(QApplication::translate("home", "Dialog", 0));
        label_6->setText(QApplication::translate("home", "\345\221\274\345\217\253\346\234\215\345\212\241", 0));
        label_5->setText(QApplication::translate("home", "\347\264\247\346\200\245\346\212\245\350\255\246", 0));
        pushButton_3->setText(QString());
        label_3->setText(QApplication::translate("home", "\346\250\241\345\274\217\351\200\211\346\213\251", 0));
        pushButton_2->setText(QString());
        label_2->setText(QApplication::translate("home", "\351\205\222\345\272\227\345\256\242\346\216\247\347\263\273\347\273\237", 0));
        pushButton_4->setText(QString());
        label_4->setText(QApplication::translate("home", "\347\216\257\345\242\203\346\216\247\345\210\266", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
