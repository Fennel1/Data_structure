#ifndef OPENADRESS_H
#define OPENADRESS_H

#include <QDialog>

namespace Ui {
class OpenAdress;
}

class OpenAdress : public QDialog
{
    Q_OBJECT

public:
    explicit OpenAdress(QWidget *parent = nullptr);
    ~OpenAdress();

private:
    Ui::OpenAdress *ui;
};

#endif // OPENADRESS_H
