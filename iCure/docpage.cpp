#include "docpage.h"
#include "ui_docpage.h"
#include "docprofile.h"
#include "docappointments.h"

docPage::docPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::docPage)
{
    ui->setupUi(this);


    connect(ui->closeBtn1, &QPushButton::clicked, this, &docPage::close);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

docPage::~docPage()
{
    delete ui;
}

void docPage::setUserId(const QString &userId)
{
    ui->label_userId->setText("User ID: " + userId);
}

void docPage::on_docProfile_btn_clicked()
{
    this->hide();
    docProfile docProfile_page;
    docProfile_page.setModal(true);
    docProfile_page.exec();
    this->show();
}

void docPage::on_docAppointment_btn_clicked()
{
    this->hide();
    docAppointments docAppontment_page;
    docAppontment_page.setModal(true);
    docAppontment_page.exec();
    this->show();
}
