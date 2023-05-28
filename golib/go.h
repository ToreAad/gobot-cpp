#pragma once
#include "gamestate.h"

class Go {
	Go(int board_size);

	std::vector<std::unique_ptr<Action>> legal_moves() const;
	bool is_over() const;
	float score(Player player) const;
	//Go apply_move(Action& action ) const;
	Player current_player() const;
	Player next_player() const;

private:
	GameState _state;
	Player _current_player;
};