#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<serialreader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	

public slots:
    void update();
	
private:
    Ui::MainWindow *ui;

    SerialReader serial_reader_;
};
#endif // MAINWINDOW_H