#include "patprofile.h"
#include "ui_patprofile.h"

patProfile::patProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patProfile)
{
    ui->setupUi(this);
}

patProfile::~patProfile()
{
    delete ui;
}

void patProfile::on_backBtn_clicked()
{
    this->close();
}
