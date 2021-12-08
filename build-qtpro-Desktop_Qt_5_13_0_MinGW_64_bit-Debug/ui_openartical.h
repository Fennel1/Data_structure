/********************************************************************************
** Form generated from reading UI file 'openartical.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENARTICAL_H
#define UI_OPENARTICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenArtical
{
public:
    QListWidget *List_Artical;

    void setupUi(QDialog *OpenArtical)
    {
        if (OpenArtical->objectName().isEmpty())
            OpenArtical->setObjectName(QString::fromUtf8("OpenArtical"));
        OpenArtical->resize(800, 600);
        List_Artical = new QListWidget(OpenArtical);
        List_Artical->setObjectName(QString::fromUtf8("List_Artical"));
        List_Artical->setGeometry(QRect(0, 0, 801, 601));
        QFont font;
        font.setPointSize(16);
        List_Artical->setFont(font);

        retranslateUi(OpenArtical);

        QMetaObject::connectSlotsByName(OpenArtical);
    } // setupUi

    void retranslateUi(QDialog *OpenArtical)
    {
        OpenArtical->setWindowTitle(QCoreApplication::translate("OpenArtical", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenArtical: public Ui_OpenArtical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENARTICAL_H
