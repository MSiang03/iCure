#ifndef DOCPAGE_H
#define DOCPAGE_H

#include <QWidget>
#include "docappointments.h"
#include "docprofile.h"

namespace Ui {
class docPage;
}

class docPage : public QWidget
{
    Q_OBJECT

public:
    explicit docPage(QWidget *parent = nullptr);
    ~docPage();

    void setUserId(const QString &userId);

private slots:
    void on_docProfile_btn_clicked();
    void on_docAppointment_btn_clicked();

private:
    Ui::docPage *ui;
};

#endif // DOCPAGE_H
