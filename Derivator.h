#pragma once
#include <QPointF>
#include <vector>

class Derivator
{
public:

	Derivator(std::vector<QPointF>& source) :source_data_(source),count(0) {}

	void update();
	void clear();
	
	std::vector<QPointF> data_;
	int count;

	std::vector<QPointF>& source_data_;
	
};

