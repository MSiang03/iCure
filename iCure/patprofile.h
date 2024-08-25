#ifndef PATPROFILE_H
#define PATPROFILE_H

#include <QDialog>

namespace Ui {
class patProfile;
}

class patProfile : public QDialog
{
    Q_OBJECT

public:
    explicit patProfile(QWidget *parent = nullptr);
    ~patProfile();

private slots:
    void on_backBtn_clicked();

private:
    Ui::patProfile *ui;
};

#endif // PATPROFILE_H
