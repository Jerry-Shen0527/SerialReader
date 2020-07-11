#ifndef CHARTPLOTTER_H
#define CHARTPLOTTER_H
#include <qobject.h>
#include <QtCharts/QtCharts>

using namespace QtCharts;

class ChartPlotter:QObject
{

	Q_OBJECT
public:
	ChartPlotter();

protected slots:
	void draw();

	
};

#endif // CHARTPLOTTER_H
