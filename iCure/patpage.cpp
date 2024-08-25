#include "patpage.h"
#include "ui_patpage.h"

patPage::patPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patPage)
{
    ui->setupUi(this);

    connect(ui->closeBtn1, &QPushButton::clicked, this, &patPage::close);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

patPage::~patPage()
{
    delete ui;
}

void patPage::setUserId(const QString &userId)
{
    ui->label_userId->setText("User Id: " + userId);
}

void patPage::on_patProfile_btn_clicked()
{
    this->hide();
    patProfile patProfile_page;
    patProfile_page.setModal(true);
    patProfile_page.exec();
    this->show();
}

void patPage::on_patAppointment_btn_clicked()
{
    this->hide();
    patAppointments patAppointment_page;
    patAppointment_page.setModal(true);
    patAppointment_page.exec();
    this->show();
}
