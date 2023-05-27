#include "gostring.h"
#include <set>

GoString::GoString()
{
	player = Player::Black;
	stones = std::set<Point>();
	liberties = std::set<Point>();
}

GoString::GoString(Player player, std::vector<Point> stones, std::vector<Point> liberties):player(player)
{
	this->stones = std::set<Point>(stones.begin(), stones.end());
	this->liberties = std::set<Point>(liberties.begin(), liberties.end());
}

GoString::GoString(Player player, std::set<Point> stones, std::set<Point> liberties)
	:player(player), stones(stones), liberties(liberties)
{
}

void GoString::remove_liberty(Point point)
{
	this->liberties.erase(point);
}

void GoString::add_liberty(Point point)
{
	this->liberties.insert(point);
}

void GoString::merge_with(const GoString* go_string)
{
	stones.insert(go_string->stones.begin(), go_string->stones.end());
	liberties.insert(go_string->liberties.begin(), go_string->liberties.end());
	for (auto stone : stones)
	{
		liberties.erase(stone);
	}
}

size_t GoString::num_liberties() const
{
	return this->liberties.size();
}

Player GoString::get_player() const
{
	return this->player;
}

std::set<Point> GoString::get_stones() const
{
	return this->stones;
}

std::set<Point> GoString::get_liberties() const
{
	return this->liberties;
}
