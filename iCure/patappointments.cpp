#include "patappointments.h"
#include "ui_patappointments.h"

patAppointments::patAppointments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::patAppointments)
{
    ui->setupUi(this);
}

patAppointments::~patAppointments()
{
    delete ui;
}

void patAppointments::on_backBtn_clicked()
{
    this->close();
}
