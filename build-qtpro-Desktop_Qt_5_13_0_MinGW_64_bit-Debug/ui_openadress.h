/********************************************************************************
** Form generated from reading UI file 'openadress.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENADRESS_H
#define UI_OPENADRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenAdress
{
public:
    QListWidget *List_AddressList;

    void setupUi(QDialog *OpenAdress)
    {
        if (OpenAdress->objectName().isEmpty())
            OpenAdress->setObjectName(QString::fromUtf8("OpenAdress"));
        OpenAdress->resize(800, 600);
        List_AddressList = new QListWidget(OpenAdress);
        List_AddressList->setObjectName(QString::fromUtf8("List_AddressList"));
        List_AddressList->setGeometry(QRect(0, 0, 800, 600));
        QFont font;
        font.setPointSize(16);
        List_AddressList->setFont(font);

        retranslateUi(OpenAdress);

        QMetaObject::connectSlotsByName(OpenAdress);
    } // setupUi

    void retranslateUi(QDialog *OpenAdress)
    {
        OpenAdress->setWindowTitle(QCoreApplication::translate("OpenAdress", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenAdress: public Ui_OpenAdress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENADRESS_H
