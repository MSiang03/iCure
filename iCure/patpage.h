#ifndef PATPAGE_H
#define PATPAGE_H

#include <QWidget>
#include "patappointments.h"
#include "patprofile.h"

namespace Ui {
class patPage;
}

class patPage : public QWidget
{
    Q_OBJECT

public:
    explicit patPage(QWidget *parent = nullptr);
    ~patPage();

    void setUserId(const QString &userId);

private slots:

    void on_patProfile_btn_clicked();

    void on_patAppointment_btn_clicked();

private:
    Ui::patPage *ui;
};

#endif // PATPAGE_H
