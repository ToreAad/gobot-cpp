#pragma once
#ifndef GOSTRING_H
#define GOSTRING_H

#include <set>
#include <cstddef>
#include "player.h"
#include "point.h"

class GoString {
	public:
		GoString();
		GoString(Player player, std::vector<Point> stones, std::vector<Point> liberties);
		GoString(Player player, std::set<Point> stones, std::set<Point> liberties);

		void remove_liberty(Point point);
		void add_liberty(Point point);
		void merge_with(const GoString* go_string);
		size_t num_liberties() const;
		Player get_player() const;
		std::set<Point> get_stones() const;
		std::set<Point> get_liberties() const;

		bool operator==(const GoString& rhs) const
		{
			return player == rhs.player && stones == rhs.stones && liberties == rhs.liberties;
		}

	private:
		std::set<Point> stones;
		std::set<Point> liberties;
		Player player;
};

#endif // !GOSTRING_H
