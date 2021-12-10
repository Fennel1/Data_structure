#ifndef CHANGEINFOPAGE_H
#define CHANGEINFOPAGE_H

#include <QDialog>

namespace Ui {
class ChangeInfoPage;
}

class ChangeInfoPage : public QDialog
{
    Q_OBJECT

private slots:  //槽函数



    void on_lineEdit_name_textEdited(const QString &arg1);

public:
    explicit ChangeInfoPage(QWidget *parent = nullptr);
    QString Str_name,Str_phone,Str_address,Str_remark,Str_email;
    ~ChangeInfoPage();


    Ui::ChangeInfoPage *ui;
};

#endif // CHANGEINFOPAGE_H
