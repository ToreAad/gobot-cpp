#pragma once
#ifndef POINT_H
#define POINT_H

#include <vector>

struct Point
{
public:
	int row;
	int col;
	Point(int _row, int _col) : row(_row), col(_col) {}
	std::vector<Point> Point::neighbours() const;

	bool operator<(const Point& rhs) const
	{
		return row < rhs.row || (row == rhs.row && col < rhs.col);
	}

	bool operator==(const Point& rhs) const
	{
		return row == rhs.row && col == rhs.col;
	}

	Point copy() const
	{
		return Point(row, col);
	}
};

#endif // !POINT_H