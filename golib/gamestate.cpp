#include "gamestate.h"

bool GameState::is_over(const GameState& state) const
{
	return false;
}

std::pair<Player, int> GameState::situation()
{
	return std::pair<Player, int>();
}

bool GameState::does_move_violate_ko(const GameState& state, const Action& action) const
{
	return false;
}

bool GameState::is_valid_move(const GameState& state, const Action& action) const
{
	return false;
}

bool GameState::is_move_self_capture(const GoBoard& board, Player player, Point point) const
{
	return false;
}

//GameState GameState::apply_move(const GameState& state, const Action& action) const
//{
//	return GameState();
//}

std::vector<Action> GameState::legal_moves() const
{
	return std::vector<Action>();
}
