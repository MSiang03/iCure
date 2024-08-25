#ifndef PATAPPOINTMENTS_H
#define PATAPPOINTMENTS_H

#include <QDialog>

namespace Ui {
class patAppointments;
}

class patAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit patAppointments(QWidget *parent = nullptr);
    ~patAppointments();

private slots:
    void on_backBtn_clicked();

private:
    Ui::patAppointments *ui;
};

#endif // PATAPPOINTMENTS_H
