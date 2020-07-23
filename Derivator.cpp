#include "Derivator.h"

void Derivator::update()
{
	const int smooth_size =2;
	if (source_data_.size() >= smooth_size)
	{
		while (count < source_data_.size() - (smooth_size - 1))
		{
			float result = 0;
			for (int i = 0; i < smooth_size-1; ++i)
			{
				float x0 = source_data_[count + i].x();
				float x1 = source_data_[count + i + 1].x();
				
				float y0 = source_data_[count + i].y();
				float y1 = source_data_[count + i + 1].y();

				result += float(y1 - y0) / (x1 - x0);
			}
			result /= float(smooth_size - 1);
			data_.emplace_back(source_data_[count + smooth_size / 2].x(), result);

			count++;
		}
	}
}

void Derivator::clear()
{
	data_.clear();

	count = 0;
}