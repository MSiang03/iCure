#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closeBtn1, &QPushButton::clicked, this, &MainWindow::close);

    setWindowFlag(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}
