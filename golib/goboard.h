#pragma once

#include <map>
#include <gostring.h>
#include <point.h>
#include <memory>



class GoBoard {
public:
	GoBoard(int size);
	unsigned int hash() const;
	void place_stone(Player player, Point point);
	void remove_string(GoString* string);
	bool is_on_grid(Point point) const;
	std::shared_ptr<GoString> get_string(Point point) const;
	Player get_player(Point point) const;
	bool is_self_capture(Player player, Point point) const;
	bool is_point_an_eye(Point point, Player player) const;

	bool operator==(const GoBoard& rhs) const
	{
		return _num_rows == rhs._num_rows && _num_cols == rhs._num_cols && _grid == rhs._grid;
	}


private:
	int _num_rows;
	int _num_cols;
	std::map<Point, std::shared_ptr<GoString>> _grid;
	unsigned int _hash;
};