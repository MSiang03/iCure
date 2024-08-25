#include "signup.h"
#include "ui_signup.h"
#include "logindialog.h"
#include <QMessageBox>
#include <QSqlError>

signUp::signUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);

    connect(ui->closeBtn, &QPushButton::clicked, this, &signUp::close);

    setWindowFlag(Qt::FramelessWindowHint);

}

signUp::~signUp()
{
    delete ui;
}

void signUp::on_signupBtn_clicked()
{
    QSqlDatabase sqlitedb;
    QString connectionName = "signupConnection";

    if (QSqlDatabase::contains(connectionName)) {
        sqlitedb = QSqlDatabase::database(connectionName);
    } else {
        sqlitedb = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        sqlitedb.setDatabaseName("/home/yeesiang/icure_database.db");
    }

    if (!sqlitedb.open()) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Failed to connect to the database."),
                             QMessageBox::Yes);
        qDebug() << "Database Error:" << sqlitedb.lastError().text();
        return;
    }

    QString username = ui->username_Line_2->text();
    QString password = ui->password_Line_2->text();
    QString cpassword = ui->password_Line2_2->text();
    QString identity;

    // Validate identity selection
    if (ui->cB_doc_2->isChecked() && ui->cB_pat_2->isChecked()) {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Please select only one identity (Doctor or Patient)."),
                             QMessageBox::Yes);
        return;
    } else if (ui->cB_doc_2->isChecked()) {
        identity = "doctor";
    } else if (ui->cB_pat_2->isChecked()) {
        identity = "patient";
    } else {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Please select an identity (Doctor or Patient)."),
                             QMessageBox::Yes);
        return;
    }


    // Validate required fields
    if (username.isEmpty() || password.isEmpty() || cpassword.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Username and password fields cannot be empty."),
                             QMessageBox::Yes);
        return;
    }

    // Confirm password match
    if (password != cpassword) {
        QMessageBox::warning(this, tr("Warning"),
                             tr("Passwords do not match."),
                             QMessageBox::Yes);
        return;
    }

    // Optional fields
    QString age = ui->age_Line_2->text();
    QString telephone = ui->telephone_Line_2->text();
    QString gender;

    if (ui->cB_male_2->isChecked()) {
        gender = "male";
    } else if (ui->cB_female_2->isChecked()) {
        gender = "female";
    } else if (ui->cB_male_2->isChecked() && ui->cB_female_2->isChecked()){
        QMessageBox::warning(this, tr("Warning"),
                             tr("Please select an gender (Male or Female)."),
                             QMessageBox::Yes);
    } else {
        gender = "";  // Leave as an empty string if not selected
    }

    QSqlQuery query(sqlitedb);
    query.prepare("INSERT INTO loginTable (username, password, identity, age, telephone, gender) "
                  "VALUES (:username, :password, :identity, :age, :telephone, :gender)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":identity", identity);
    query.bindValue(":age", age.isEmpty() ? QVariant(QVariant::Int) : age.toInt());
    query.bindValue(":telephone", telephone.isEmpty() ? QVariant(QVariant::LongLong) : telephone.toLongLong());
    query.bindValue(":gender", gender.isEmpty() ? QVariant(QVariant::String) : gender);

    if (!query.exec()) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Failed to sign up. Please try again."),
                             QMessageBox::Yes);
        qDebug() << "Insert Error:" << query.lastError().text();
    } else {
        QMessageBox::information(this, tr("Success"),
                                 tr("Sign-up successful!"),
                                 QMessageBox::Yes);
        loginDialog *loginPage = new loginDialog();
        this->hide();
        loginPage->show();
    }

    query.clear();  // Clear the query to ensure it's done
    sqlitedb.close();  // Close the database connection

    // Remove the connection safely
    QSqlDatabase::removeDatabase(connectionName);
}
