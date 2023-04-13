#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "echointerface.h"

MainWindow::MainWindow(EchoInterface* in, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), echo_module_(in)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (echo_module_)
    {
        ui->textEdit->append(echo_module_->Echo("sdfsdfsdf"));
    }
}

