/********************************************************************************
** Form generated from reading UI file 'connectmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTMENU_H
#define UI_CONNECTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_connectmenu
{
public:
    QPushButton *sever;
    QPushButton *pushButton_2;
    QLineEdit *severport;
    QLineEdit *IP;
    QLineEdit *PORT;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *connectmenu)
    {
        if (connectmenu->objectName().isEmpty())
            connectmenu->setObjectName("connectmenu");
        connectmenu->resize(429, 241);
        connectmenu->setMinimumSize(QSize(429, 241));
        connectmenu->setMaximumSize(QSize(429, 241));
        sever = new QPushButton(connectmenu);
        sever->setObjectName("sever");
        sever->setGeometry(QRect(330, 40, 80, 31));
        pushButton_2 = new QPushButton(connectmenu);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 170, 80, 31));
        severport = new QLineEdit(connectmenu);
        severport->setObjectName("severport");
        severport->setGeometry(QRect(150, 40, 113, 20));
        IP = new QLineEdit(connectmenu);
        IP->setObjectName("IP");
        IP->setGeometry(QRect(60, 170, 113, 20));
        PORT = new QLineEdit(connectmenu);
        PORT->setObjectName("PORT");
        PORT->setGeometry(QRect(210, 170, 113, 20));
        label = new QLabel(connectmenu);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 120, 121, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font.setPointSize(22);
        label->setFont(font);
        label_2 = new QLabel(connectmenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 110, 111, 81));
        label_2->setFont(font);
        label_3 = new QLabel(connectmenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 141, 31));
        label_3->setFont(font);

        retranslateUi(connectmenu);

        QMetaObject::connectSlotsByName(connectmenu);
    } // setupUi

    void retranslateUi(QDialog *connectmenu)
    {
        connectmenu->setWindowTitle(QCoreApplication::translate("connectmenu", "Dialog", nullptr));
        sever->setText(QCoreApplication::translate("connectmenu", "\345\210\233\345\273\272\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("connectmenu", "\345\212\240\345\205\245\346\270\270\346\210\217", nullptr));
        label->setText(QCoreApplication::translate("connectmenu", "ip\345\234\260\345\235\200\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("connectmenu", "\347\253\257\345\217\243\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("connectmenu", "\344\270\273\346\234\272\347\253\257\345\217\243\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connectmenu: public Ui_connectmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTMENU_H
