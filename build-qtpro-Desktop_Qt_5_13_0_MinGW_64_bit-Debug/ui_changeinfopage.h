/********************************************************************************
** Form generated from reading UI file 'changeinfopage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFOPAGE_H
#define UI_CHANGEINFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfoPage
{
public:
    QLabel *label_name;
    QLabel *label_phone;
    QLabel *label_address;
    QLabel *label_remark;
    QLabel *label_email;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_remark;
    QLineEdit *lineEdit_email;
    QPushButton *pushButton;

    void setupUi(QDialog *ChangeInfoPage)
    {
        if (ChangeInfoPage->objectName().isEmpty())
            ChangeInfoPage->setObjectName(QString::fromUtf8("ChangeInfoPage"));
        ChangeInfoPage->resize(583, 452);
        label_name = new QLabel(ChangeInfoPage);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(60, 60, 72, 21));
        label_phone = new QLabel(ChangeInfoPage);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setGeometry(QRect(60, 90, 72, 15));
        label_address = new QLabel(ChangeInfoPage);
        label_address->setObjectName(QString::fromUtf8("label_address"));
        label_address->setGeometry(QRect(60, 120, 72, 15));
        label_remark = new QLabel(ChangeInfoPage);
        label_remark->setObjectName(QString::fromUtf8("label_remark"));
        label_remark->setGeometry(QRect(60, 150, 72, 15));
        label_email = new QLabel(ChangeInfoPage);
        label_email->setObjectName(QString::fromUtf8("label_email"));
        label_email->setGeometry(QRect(60, 180, 72, 15));
        lineEdit_name = new QLineEdit(ChangeInfoPage);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(120, 60, 361, 41));
        lineEdit_phone = new QLineEdit(ChangeInfoPage);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(120, 90, 113, 21));
        lineEdit_address = new QLineEdit(ChangeInfoPage);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        lineEdit_address->setGeometry(QRect(130, 120, 113, 21));
        lineEdit_remark = new QLineEdit(ChangeInfoPage);
        lineEdit_remark->setObjectName(QString::fromUtf8("lineEdit_remark"));
        lineEdit_remark->setGeometry(QRect(130, 150, 113, 21));
        lineEdit_email = new QLineEdit(ChangeInfoPage);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(130, 180, 113, 21));
        pushButton = new QPushButton(ChangeInfoPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 260, 93, 28));

        retranslateUi(ChangeInfoPage);

        QMetaObject::connectSlotsByName(ChangeInfoPage);
    } // setupUi

    void retranslateUi(QDialog *ChangeInfoPage)
    {
        ChangeInfoPage->setWindowTitle(QCoreApplication::translate("ChangeInfoPage", "Dialog", nullptr));
        label_name->setText(QCoreApplication::translate("ChangeInfoPage", "Name:", nullptr));
        label_phone->setText(QCoreApplication::translate("ChangeInfoPage", "Phone:", nullptr));
        label_address->setText(QCoreApplication::translate("ChangeInfoPage", "Address:", nullptr));
        label_remark->setText(QCoreApplication::translate("ChangeInfoPage", "Remark:", nullptr));
        label_email->setText(QCoreApplication::translate("ChangeInfoPage", "Email:", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        lineEdit_address->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        lineEdit_remark->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "un@known.com", nullptr));
        pushButton->setText(QCoreApplication::translate("ChangeInfoPage", "YES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfoPage: public Ui_ChangeInfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFOPAGE_H
