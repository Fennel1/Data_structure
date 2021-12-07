#ifndef OPENADRESS_H
#define OPENADRESS_H

#include <QDialog>
#include <QListWidgetItem>
#include <QtDebug>
#include <QString>
#include <Qdir>

#include "address.h"

namespace Ui {
class OpenAdress;
}

class OpenAdress : public QDialog
{
    Q_OBJECT

public slots:   //槽函数

public:
    explicit OpenAdress(QWidget *parent = nullptr);
    void set_List();
    ~OpenAdress();

    Ui::OpenAdress *ui;
};

#endif // OPENADRESS_H
