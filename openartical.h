#ifndef OPENARTICAL_H
#define OPENARTICAL_H

#include <QDialog>
#include <QListWidgetItem>
#include <QtDebug>
#include <QString>
#include <Qdir>

namespace Ui {
class OpenArtical;
}

class OpenArtical : public QDialog
{
    Q_OBJECT

public slots:   //槽函数

public:
    explicit OpenArtical(QWidget *parent = nullptr);
    void set_List();
    ~OpenArtical();

    Ui::OpenArtical *ui;
};

#endif // OPENARTICAL_H
