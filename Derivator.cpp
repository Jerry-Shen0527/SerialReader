#include "Derivator.h"

void Derivator::update()
{
	if (source_data_.size() >= 2)
	{
		while (count < source_data_.size() - 1)
		{
			auto x1 = source_data_[count].x();
			auto x2 = source_data_[count + 1].x();
			auto y1 = source_data_[count].y();
			auto y2 = source_data_[count + 1].y();
			data_.emplace_back(float(x1 + x2) / 2.0f,float(y2 - y1) / (x2 - x1));

			count++;
		}
	}
}

void Derivator::clear()
{
	data_.clear();

	count = 0;
}
