#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(&serial_reader_, &SerialReader::sig, this, &MainWindow::update);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::update()
{
	ui->lcdNumber->display(serial_reader_.top());
}