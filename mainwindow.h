#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QtCharts>

#include <QMainWindow>
#include<serialreader.h>
#include <chartplotter.h>

#include "Derivator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

public slots:
	void update();
	void clear();

private:
	Ui::MainWindow* ui;

	SerialReader serial_reader_;

	ChartPlotter chart_plotter_s_;
	ChartPlotter chart_plotter_v_;
	ChartPlotter chart_plotter_a_;
	ChartPlotter chart_plotter_s_a_;

	Derivator d_s_v_;
	Derivator d_v_a_;

	std::vector<QPointF> s_to_a_;

	int count = 1;

	double time_begin_ = 0;

	bool read = false;
};
#endif // MAINWINDOW_H
