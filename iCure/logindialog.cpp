#include "logindialog.h"
#include "ui_logindialog.h"
#include "docpage.h"
#include "patpage.h"
#include "signup.h"
#include <QMessageBox>
#include <QPixmap>

loginDialog::loginDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginDialog)
{
    ui->setupUi(this);

    sqlitedb = QSqlDatabase::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName("/home/yeesiang/icure_database.db");

    QPixmap pix("/home/yeesiang/iCure1.1/login_icure/res/hospital.jpg");
    ui->label_pic->setPixmap(pix.scaled(400,400,Qt::KeepAspectRatio));

    connect(ui->closeBtn, &QPushButton::clicked, this, &loginDialog::close);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

loginDialog::~loginDialog()
{
    delete ui;
}


void loginDialog::on_loginBtn_clicked()
{
    QString username = ui->usrLineEdit->text();
    QString password = ui->pwdLineEdit->text();


    if (sqlitedb.open()){

        QSqlQuery query(sqlitedb);
        query.prepare("SELECT * FROM loginTable WHERE username = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (query.exec()){
            if(query.next()){
//                QMessageBox::information(this, tr("Congrats"),
//                                     tr("Login Success"),
//                                     QMessageBox::Yes);

                // Store the ID and identity
                QString userId = query.value(0).toString();
                QString userIdentity = query.value(3).toString();

                // Navigate to the appropriate main page based on identity
                if (userIdentity == "doctor") {
                    docPage *doctorPage = new docPage();
                    this->hide();
                    doctorPage->setUserId(userId);
                    doctorPage->show();
                } else if (userIdentity == "patient") {
                    patPage *patientPage = new patPage();
                    this->hide();
                    patientPage->setUserId(userId);
                    patientPage->show();
                }



                //accept();  // Close the dialog after successful login
            }
            else {
                QMessageBox::warning(this, tr("Warning"),
                                     tr("Invalid username or password"),
                                     QMessageBox::Yes);
            }
        }
        else {
                QMessageBox::warning(this, tr("Warning"),
                                     tr("Login failed due to database error"),
                                     QMessageBox::Yes);
            }
    }
    else {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Failed to connect database"),
                             QMessageBox::Yes);
    }

    sqlitedb.close();
}

void loginDialog::on_gosignupBtn_clicked()
{
    signUp *signupPage = new signUp();
    this->close();
    signupPage->show();
}
