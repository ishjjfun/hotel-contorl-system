/********************************************************************************
** Form generated from reading UI file 'equipmentcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENTCONTROL_H
#define UI_EQUIPMENTCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_equipmentcontrol
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QLabel *label_5;

    void setupUi(QDialog *equipmentcontrol)
    {
        if (equipmentcontrol->objectName().isEmpty())
            equipmentcontrol->setObjectName(QStringLiteral("equipmentcontrol"));
        equipmentcontrol->resize(947, 542);
        pushButton = new QPushButton(equipmentcontrol);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 160, 161, 151));
        pushButton->setStyleSheet(QStringLiteral("border-image: url(:/pic/chuanglian.png);"));
        pushButton_2 = new QPushButton(equipmentcontrol);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 130, 161, 191));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/pic/kongtiaomoduanjiankongxitong.png);"));
        pushButton_3 = new QPushButton(equipmentcontrol);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 350, 41, 41));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/pic/76xinzeng.png);"));
        pushButton_4 = new QPushButton(equipmentcontrol);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(630, 350, 41, 41));
        pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/pic/jianshao.png);"));
        label = new QLabel(equipmentcontrol);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 340, 71, 61));
        label->setStyleSheet(QStringLiteral("font: 18pt \"Sans Serif\";"));
        label_2 = new QLabel(equipmentcontrol);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 10, 191, 91));
        label_2->setStyleSheet(QLatin1String("font: 75 26pt \"Century Schoolbook L\";\n"
""));
        pushButton_5 = new QPushButton(equipmentcontrol);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 20, 61, 71));
        pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/pic/xiangzuo (1).png);"));
        pushButton_6 = new QPushButton(equipmentcontrol);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 350, 51, 41));
        pushButton_6->setStyleSheet(QStringLiteral("border-image: url(:/pic/tubiaozhizuo-.png);"));
        pushButton_7 = new QPushButton(equipmentcontrol);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(290, 350, 51, 41));
        pushButton_7->setStyleSheet(QStringLiteral("border-image: url(:/pic/tubiaozhizuo- (1).png);"));
        label_3 = new QLabel(equipmentcontrol);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 340, 51, 51));
        label_3->setStyleSheet(QStringLiteral("font: 18pt \"Sans Serif\";"));
        label_4 = new QLabel(equipmentcontrol);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 390, 181, 41));
        pushButton_8 = new QPushButton(equipmentcontrol);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(430, 40, 131, 51));
        pushButton_9 = new QPushButton(equipmentcontrol);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(590, 40, 131, 51));
        label_5 = new QLabel(equipmentcontrol);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(480, 90, 191, 51));

        retranslateUi(equipmentcontrol);

        QMetaObject::connectSlotsByName(equipmentcontrol);
    } // setupUi

    void retranslateUi(QDialog *equipmentcontrol)
    {
        equipmentcontrol->setWindowTitle(QApplication::translate("equipmentcontrol", "Dialog", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("equipmentcontrol", "\347\216\257\345\242\203\346\216\247\345\210\266", 0));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("equipmentcontrol", "\345\276\200\345\267\246\350\276\271\347\232\204\350\267\235\347\246\2730-10", 0));
        pushButton_8->setText(QApplication::translate("equipmentcontrol", "\346\231\272\350\203\275\350\260\203\346\216\247", 0));
        pushButton_9->setText(QApplication::translate("equipmentcontrol", "\350\260\203\346\216\247\345\205\263\351\227\255", 0));
        label_5->setText(QApplication::translate("equipmentcontrol", "\345\256\244\346\270\251\346\216\247\345\210\266\344\270\27225\342\204\203 \347\252\227\345\270\230\345\256\236\346\227\266\350\260\203\346\225\264", 0));
    } // retranslateUi

};

namespace Ui {
    class equipmentcontrol: public Ui_equipmentcontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENTCONTROL_H
