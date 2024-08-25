#include "docappointments.h"
#include "ui_docappointments.h"

docAppointments::docAppointments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::docAppointments)
{
    ui->setupUi(this);
}

docAppointments::~docAppointments()
{
    delete ui;
}

void docAppointments::on_backBtn_clicked()
{
    this->close();
}
