#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class signUp;
}

class signUp : public QWidget
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();

private slots:
    void on_signupBtn_clicked();

private:
    Ui::signUp *ui;
};

#endif // SIGNUP_H
