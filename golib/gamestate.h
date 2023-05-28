#pragma once
#include "goboard.h"
#include "action.h"

class GameState
{
	bool is_over(const GameState& state) const;
	std::pair<Player, int> situation();
	bool does_move_violate_ko(const GameState& state, const Action& action) const;
	bool is_valid_move(const GameState& state, const Action& action) const;
	bool is_move_self_capture(const GoBoard& board, Player player, Point point) const;
	//GameState apply_move(const GameState& state, const Action& action) const;
	std::vector<Action> legal_moves() const;

	GameState(int size);

private:
	GoBoard _board;
	Player _next_player;
	std::unique_ptr<Action> _last_action;
	GameState* _previous_state;
};