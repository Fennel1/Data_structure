/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *PB_AddressList;
    QPushButton *PB_Text;
    QPushButton *PB_AllAdress;
    QPushButton *PB_QueryAdress;
    QPushButton *PB_GroupAdress;
    QPushButton *PB_TextInfo;
    QPushButton *PB_DiffHashfun;
    QPushButton *PB_DiffConflict;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2160, 1350);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PB_AddressList = new QPushButton(centralWidget);
        PB_AddressList->setObjectName(QString::fromUtf8("PB_AddressList"));
        PB_AddressList->setGeometry(QRect(0, 0, 1080, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        PB_AddressList->setFont(font);
        PB_AddressList->setIconSize(QSize(16, 16));
        PB_Text = new QPushButton(centralWidget);
        PB_Text->setObjectName(QString::fromUtf8("PB_Text"));
        PB_Text->setGeometry(QRect(1080, 0, 1080, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        PB_Text->setFont(font1);
        PB_AllAdress = new QPushButton(centralWidget);
        PB_AllAdress->setObjectName(QString::fromUtf8("PB_AllAdress"));
        PB_AllAdress->setEnabled(true);
        PB_AllAdress->setGeometry(QRect(0, 100, 720, 90));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        PB_AllAdress->setFont(font2);
        PB_AllAdress->setIconSize(QSize(16, 16));
        PB_QueryAdress = new QPushButton(centralWidget);
        PB_QueryAdress->setObjectName(QString::fromUtf8("PB_QueryAdress"));
        PB_QueryAdress->setGeometry(QRect(720, 100, 720, 90));
        PB_QueryAdress->setFont(font2);
        PB_QueryAdress->setIconSize(QSize(16, 16));
        PB_GroupAdress = new QPushButton(centralWidget);
        PB_GroupAdress->setObjectName(QString::fromUtf8("PB_GroupAdress"));
        PB_GroupAdress->setGeometry(QRect(1440, 100, 720, 90));
        PB_GroupAdress->setFont(font2);
        PB_GroupAdress->setIconSize(QSize(16, 16));
        PB_TextInfo = new QPushButton(centralWidget);
        PB_TextInfo->setObjectName(QString::fromUtf8("PB_TextInfo"));
        PB_TextInfo->setEnabled(true);
        PB_TextInfo->setGeometry(QRect(0, 100, 720, 90));
        PB_TextInfo->setFont(font2);
        PB_TextInfo->setIconSize(QSize(16, 16));
        PB_DiffHashfun = new QPushButton(centralWidget);
        PB_DiffHashfun->setObjectName(QString::fromUtf8("PB_DiffHashfun"));
        PB_DiffHashfun->setEnabled(true);
        PB_DiffHashfun->setGeometry(QRect(720, 100, 720, 90));
        PB_DiffHashfun->setFont(font2);
        PB_DiffHashfun->setIconSize(QSize(16, 16));
        PB_DiffConflict = new QPushButton(centralWidget);
        PB_DiffConflict->setObjectName(QString::fromUtf8("PB_DiffConflict"));
        PB_DiffConflict->setEnabled(true);
        PB_DiffConflict->setGeometry(QRect(1440, 100, 720, 90));
        PB_DiffConflict->setFont(font2);
        PB_DiffConflict->setIconSize(QSize(16, 16));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        PB_TextInfo->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PB_AddressList->setText(QCoreApplication::translate("MainWindow", "\351\200\232\350\256\257\345\275\225", nullptr));
        PB_Text->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\347\273\237\350\256\241", nullptr));
        PB_AllAdress->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250", nullptr));
        PB_QueryAdress->setText(QCoreApplication::translate("MainWindow", "\345\210\206\347\273\204", nullptr));
        PB_GroupAdress->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        PB_TextInfo->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241", nullptr));
        PB_DiffHashfun->setText(QCoreApplication::translate("MainWindow", "\346\257\224\350\276\203\344\270\215\345\220\214\345\223\210\345\270\214\345\207\275\346\225\260", nullptr));
        PB_DiffConflict->setText(QCoreApplication::translate("MainWindow", "\346\257\224\350\276\203\344\270\215\345\220\214\345\244\204\347\220\206\345\206\262\347\252\201\346\226\271\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
