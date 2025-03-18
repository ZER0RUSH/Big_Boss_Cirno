/********************************************************************************
** Form generated from reading UI file 'startmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTMENU_H
#define UI_STARTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_startmenu
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *oneplayer;
    QPushButton *twopalyer;
    QPushButton *exit;

    void setupUi(QDialog *startmenu)
    {
        if (startmenu->objectName().isEmpty())
            startmenu->setObjectName("startmenu");
        startmenu->resize(523, 388);
        startmenu->setMinimumSize(QSize(523, 388));
        startmenu->setMaximumSize(QSize(523, 388));
        label = new QLabel(startmenu);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 421, 131));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200")});
        font.setPointSize(36);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(startmenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 290, 291, 91));
        label_3 = new QLabel(startmenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 190, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200")});
        font1.setPointSize(20);
        label_3->setFont(font1);
        oneplayer = new QPushButton(startmenu);
        oneplayer->setObjectName("oneplayer");
        oneplayer->setGeometry(QRect(120, 230, 101, 31));
        twopalyer = new QPushButton(startmenu);
        twopalyer->setObjectName("twopalyer");
        twopalyer->setGeometry(QRect(310, 230, 101, 31));
        exit = new QPushButton(startmenu);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(400, 330, 91, 31));

        retranslateUi(startmenu);

        QMetaObject::connectSlotsByName(startmenu);
    } // setupUi

    void retranslateUi(QDialog *startmenu)
    {
        startmenu->setWindowTitle(QCoreApplication::translate("startmenu", "Homo\351\246\206", nullptr));
        label->setText(QCoreApplication::translate("startmenu", "\346\201\220\346\200\226\351\255\224\347\216\213\347\220\252\351\234\262\350\257\272", nullptr));
        label_2->setText(QCoreApplication::translate("startmenu", "\344\275\234\350\200\205\357\274\232\346\236\227\347\201\277\350\261\252 \350\213\217\350\276\276\351\222\212 \346\264\252\345\256\207\346\266\233", nullptr));
        label_3->setText(QCoreApplication::translate("startmenu", "\351\200\211\346\213\251\346\250\241\345\274\217\357\274\232", nullptr));
        oneplayer->setText(QCoreApplication::translate("startmenu", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        twopalyer->setText(QCoreApplication::translate("startmenu", "\345\217\214\344\272\272\345\220\210\344\275\234", nullptr));
        exit->setText(QCoreApplication::translate("startmenu", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startmenu: public Ui_startmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTMENU_H
