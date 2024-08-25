#ifndef DOCAPPOINTMENTS_H
#define DOCAPPOINTMENTS_H

#include <QDialog>
#include "docpage.h"

namespace Ui {
class docAppointments;
}

class docAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit docAppointments(QWidget *parent = nullptr);
    ~docAppointments();

private slots:
    void on_backBtn_clicked();

private:
    Ui::docAppointments *ui;
};

#endif // DOCAPPOINTMENTS_H
