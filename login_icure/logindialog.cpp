#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QPixmap>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);

    QPixmap pix("/home/yeesiang/login_icure/res/hospital.jpg");
    ui->label_pic->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio));

    connect(ui->closeBtn, &QPushButton::clicked, this, &loginDialog::close);

    setWindowFlag(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground, true);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginBtn_clicked()
{
    QSqlDatabase sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName("/home/yeesiang/icure_database.db");

    QString username = ui->usrLineEdit->text();
    QString password = ui->pwdLineEdit->text();

    if (sqlitedb.open())
    {
        QSqlQuery query(sqlitedb);
        query.prepare("SELECT * FROM loginTable WHERE username = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (query.exec()){
            if(query.next()){
                accept();
            }
            else {
                QMessageBox::warning(this,tr("Warning"),
                                     tr("Invalid username or password"),
                                     QMessageBox::Yes);
            }

        }
        else {
            QMessageBox::warning(this,tr("Warning"),
                                 tr("Login failed database error"),
                                 QMessageBox::Yes);
        }
    }
    else {
        QMessageBox::warning(this,tr("Warning"),
                             tr("Connection failed!"),
                             QMessageBox::Yes);
    }
    sqlitedb.close();
}

void loginDialog::on_exitBtn_clicked()
{
}
