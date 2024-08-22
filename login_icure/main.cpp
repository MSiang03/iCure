#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    loginDialog dlg;
//    QPushButton button("Quit");
//    QObject::connect(&button, &QPushButton::clicked,
//                     &app, &QApplication::quit);
//    button.show();
    if(dlg.exec()==QDialog::Accepted){
        w.show();
//        button.show();
        return app.exec();
    }else{
        return 0;
    }
}
