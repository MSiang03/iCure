#ifndef DOCPROFILE_H
#define DOCPROFILE_H

#include <QDialog>
#include <docpage.h>

namespace Ui {
class docProfile;
}

class docProfile : public QDialog
{
    Q_OBJECT

public:
    explicit docProfile(QWidget *parent = nullptr);
    ~docProfile();

private slots:
    void on_backBtn_clicked();

private:
    Ui::docProfile *ui;
};

#endif // DOCPROFILE_H
