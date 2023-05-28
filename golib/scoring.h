#pragma once
#include <goboard.h>

class GameResult{
	float score(Player player) const;
	float winning_margin() const;

	GameResult(const GoBoard& board, float komi);

private:
	float _black_score;
	float _white_score;
	float _komi;
};

enum TerritoryState {
	TS_Black,
	TS_BlackTerritory,
	TS_White,
	TS_WhiteTerritory,
	TS_Dame,
};

class Territory {
	Territory(std::map<Point, TerritoryState> territory_map);
	float black_score();
	float white_score();

private:
	int _num_black_territory;
	int _num_white_territory;
	int _num_black_stones;
	int _num_white_stones;
	int _num_dame;
	std::vector<Point> _dame_points;
};

