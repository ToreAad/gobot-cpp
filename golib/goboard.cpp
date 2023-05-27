#include "goboard.h"
#include <set>
#include <zoobrist.h>
#include <memory>
#include <algorithm>


GoBoard::GoBoard(int size) : _num_rows(size), _num_cols(size)
{
}

unsigned int GoBoard::hash() const
{
	return this->_hash;
}

void GoBoard::place_stone(Player player, Point point)
{
	if (!this->is_on_grid(point))
	{
		return;
	}

	if (this->get_player(point) != Player::None)
	{
		return;
	}

	auto adjacent_same_color = std::vector<std::shared_ptr<GoString>>();
	auto adjacent_opposite_color = std::vector<std::shared_ptr<GoString>>();
	auto liberties = std::vector<Point>();

	for (auto& neighbour : point.neighbours()) {
		if (!this->is_on_grid(neighbour))
		{
			continue;
		}
		auto neighbour_string = this->get_string(neighbour);

		if (neighbour_string == nullptr)
		{
			liberties.push_back(neighbour);
		}
		else if (neighbour_string->get_player() == player)
		{
			if (std::find(adjacent_same_color.begin(), adjacent_same_color.end(), neighbour_string) != adjacent_same_color.end())
			{
				continue;
			}
			adjacent_same_color.push_back(neighbour_string);
		}
		else
		{
			if (std::find(adjacent_opposite_color.begin(), adjacent_opposite_color.end(), neighbour_string) != adjacent_opposite_color.end())
			{
				continue;
			}
			adjacent_opposite_color.push_back(neighbour_string);
		}
	}

	auto new_string = std::make_shared<GoString>(GoString(player, { point }, liberties));

	for (auto same_color_string : adjacent_same_color) {
		new_string->merge_with(same_color_string.get());
	}

	for (auto& new_string_points : new_string->get_stones())
	{
		this->_grid[new_string_points] = new_string;
	}

	auto t = get_zoobrist_hash(point.row, point.col, player);
	this->_hash ^= t;

	for (auto& other_color_string : adjacent_opposite_color)
	{
		other_color_string->remove_liberty(point);
		if (other_color_string->num_liberties() == 0) {
			this->remove_string(other_color_string.get());
		}
	}
}

void GoBoard::remove_string(GoString* string)
{
	for (auto& point : string->get_stones()) {
		for (auto& neighbour : point.neighbours()) {
			if(!this->is_on_grid(neighbour)) 
				continue;
			auto maybe_neighbour = get_string(neighbour);
			if(maybe_neighbour == nullptr) 
				continue;
			if (maybe_neighbour->get_player() != string->get_player()) {
				maybe_neighbour->add_liberty(point);
			}
		}
		this->_grid.erase(point);
		this->_hash ^= get_zoobrist_hash(point.row, point.col, string->get_player());
	}
}

bool GoBoard::is_on_grid(Point point) const
{
	return point.row >= 1 && point.row <= this->_num_rows &&
		point.col >= 1 && point.col <= this->_num_cols;
}

std::shared_ptr<GoString> GoBoard::get_string(Point point) const
{
	auto it = _grid.find(point);
	if (it != _grid.end())
	{
		return it->second;
	}
	return nullptr;
}

Player GoBoard::get_player(Point point) const
{
	auto go_string = this->get_string(point);
	if (go_string == nullptr)
	{
		return Player::None;
	}
	return go_string->get_player();
}


bool GoBoard::is_self_capture(Player player, Point point) const
{
	auto friendly_strings = std::vector<GoString*>();
	for (auto& neighbour : point.neighbours()) {
		if (!this->is_on_grid(neighbour)) 
			continue;
		auto neighbour_string = this->get_string(neighbour);
		if (neighbour_string == nullptr) 
			return false;
		if (neighbour_string->get_player() == player) {
			friendly_strings.push_back(neighbour_string.get());
		}
		else {
			if (neighbour_string->num_liberties() == 1) {
				return false;
			}
		}
	}
	if (std::all_of(friendly_strings.begin(), friendly_strings.end(), [](GoString* x) { return x->num_liberties() == 1; })) {
		return true;
	}
	return false;
}

bool GoBoard::is_point_an_eye(Point point, Player player) const
{
	if (!this->is_on_grid(point)) {
		return false;
	}
	if (this->get_player(point) != Player::None) {
		return false;
	}
	for (auto& neighbour : point.neighbours()) {
		auto other_player = this->get_player(neighbour);
		if (other_player == Player::None)
			continue;
		if(other_player != player)
			return false;
	}

	auto friendly_corners = 0;
	auto off_board_corners = 0;
	auto corners = std::vector<Point>{ Point(point.row - 1, point.col - 1), Point(point.row - 1, point.col + 1), Point(point.row + 1, point.col - 1), Point(point.row + 1, point.col + 1) };
	for (auto& corner : corners) {
		if (!this->is_on_grid(corner)) {
			off_board_corners += 1;
			continue;
		}
		auto corner_player = this->get_player(corner);
		if (corner_player == player) {
			friendly_corners += 1;
		}
	}

	if (off_board_corners > 0) {
		return off_board_corners + friendly_corners == 4;
	}

	return friendly_corners >= 3;
}
