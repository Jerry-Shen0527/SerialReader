#ifndef CHARTPLOTTER_H
#define CHARTPLOTTER_H
#include <qobject.h>
#include <QtCharts/QtCharts>

using namespace QtCharts;

class ChartPlotter
{
public:
	ChartPlotter(const char* name);
	~ChartPlotter();

	void clear();
	
	QChart* chart;
	QLineSeries* line;

	int count;
	void update(std::vector<QPointF>& rata_);

	void draw(QChartView* chart_view);
};

#endif // CHARTPLOTTER_H
