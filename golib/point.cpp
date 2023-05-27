#include "point.h"

std::vector<Point> Point::neighbours() const
{
	std::vector<Point> result;
	result.push_back(Point(row - 1, col));
	result.push_back(Point(row + 1, col));
	result.push_back(Point(row, col - 1));
	result.push_back(Point(row, col + 1));
	return result;
}