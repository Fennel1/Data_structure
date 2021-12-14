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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfoPage
{
public:
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_name;
    QSpacerItem *verticalSpacer;
    QLabel *label_phone;
    QLineEdit *lineEdit_phone;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_address;
    QLineEdit *lineEdit_address;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_remark;
    QLineEdit *lineEdit_remark;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_name;

    void setupUi(QDialog *ChangeInfoPage)
    {
        if (ChangeInfoPage->objectName().isEmpty())
            ChangeInfoPage->setObjectName(QString::fromUtf8("ChangeInfoPage"));
        ChangeInfoPage->resize(800, 600);
        ChangeInfoPage->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton = new QPushButton(ChangeInfoPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(620, 520, 150, 40));
        formLayoutWidget = new QWidget(ChangeInfoPage);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 50, 691, 441));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(formLayoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_name->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_name);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        label_phone = new QLabel(formLayoutWidget);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));
        label_phone->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_phone);

        lineEdit_phone = new QLineEdit(formLayoutWidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_phone);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::FieldRole, verticalSpacer_2);

        label_address = new QLabel(formLayoutWidget);
        label_address->setObjectName(QString::fromUtf8("label_address"));
        label_address->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_address);

        lineEdit_address = new QLineEdit(formLayoutWidget);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_address);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::FieldRole, verticalSpacer_3);

        label_remark = new QLabel(formLayoutWidget);
        label_remark->setObjectName(QString::fromUtf8("label_remark"));
        label_remark->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_remark);

        lineEdit_remark = new QLineEdit(formLayoutWidget);
        lineEdit_remark->setObjectName(QString::fromUtf8("lineEdit_remark"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_remark);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::FieldRole, verticalSpacer_4);

        label_email = new QLabel(formLayoutWidget);
        label_email->setObjectName(QString::fromUtf8("label_email"));
        label_email->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_email);

        lineEdit_email = new QLineEdit(formLayoutWidget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_email);

        lineEdit_name = new QLineEdit(formLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);


        retranslateUi(ChangeInfoPage);

        QMetaObject::connectSlotsByName(ChangeInfoPage);
    } // setupUi

    void retranslateUi(QDialog *ChangeInfoPage)
    {
        ChangeInfoPage->setWindowTitle(QCoreApplication::translate("ChangeInfoPage", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("ChangeInfoPage", "YES", nullptr));
        label_name->setText(QCoreApplication::translate("ChangeInfoPage", "Name:", nullptr));
        label_phone->setText(QCoreApplication::translate("ChangeInfoPage", "Phone:", nullptr));
        lineEdit_phone->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        label_address->setText(QCoreApplication::translate("ChangeInfoPage", "Address:", nullptr));
        lineEdit_address->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        label_remark->setText(QCoreApplication::translate("ChangeInfoPage", "Remark:", nullptr));
        lineEdit_remark->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
        label_email->setText(QCoreApplication::translate("ChangeInfoPage", "Email:", nullptr));
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "un@known.com", nullptr));
        lineEdit_name->setPlaceholderText(QCoreApplication::translate("ChangeInfoPage", "unknown", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfoPage: public Ui_ChangeInfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFOPAGE_H
