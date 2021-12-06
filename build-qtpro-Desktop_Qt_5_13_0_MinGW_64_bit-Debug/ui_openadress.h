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
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_OpenAdress
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OpenAdress)
    {
        if (OpenAdress->objectName().isEmpty())
            OpenAdress->setObjectName(QString::fromUtf8("OpenAdress"));
        OpenAdress->resize(400, 300);
        buttonBox = new QDialogButtonBox(OpenAdress);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(OpenAdress);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpenAdress, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpenAdress, SLOT(reject()));

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
