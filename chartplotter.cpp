#include "chartplotter.h"

ChartPlotter::ChartPlotter(const char* name)
{
	count = 0;
	line = new QLineSeries();
	chart = new QChart();
	chart->setTitle(name);

	
}

ChartPlotter::~ChartPlotter()
{
	delete line;
	line = nullptr;
	delete chart;
	chart = nullptr;
}

void ChartPlotter::clear()
{
	line->clear();
	count = 0;
}

void ChartPlotter::update(std::vector<QPointF>& data_)
{
	while (count < data_.size())
	{
		line->append(data_[count]);
		count++;
	}
}

void ChartPlotter::draw(QChartView* chart_view)
{
	chart->legend()->hide();
	//chart->removeAllSeries();
	chart->removeSeries(line);
	chart->addSeries(line);
	chart->createDefaultAxes();

	chart_view->setChart(chart);
	chart_view->setRenderHint(QPainter::Antialiasing);
}