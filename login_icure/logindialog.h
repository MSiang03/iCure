#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

private slots:
    void on_loginBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
