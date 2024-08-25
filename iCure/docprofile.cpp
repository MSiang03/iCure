#include "docprofile.h"
#include "ui_docprofile.h"

docProfile::docProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::docProfile)
{
    ui->setupUi(this);
}

docProfile::~docProfile()
{
    delete ui;
}

void docProfile::on_backBtn_clicked()
{
    this->close();
}
