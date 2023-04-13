#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class EchoInterface;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(EchoInterface* in, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    EchoInterface* echo_module_;
};
#endif // MAINWINDOW_H
