#include "go.h"
#include "action.h"


std::vector<std::unique_ptr<Action>> Go::legal_moves() const
{
    return std::vector<std::unique_ptr<Action>>();
}

bool Go::is_over() const
{
    return false;
}

float Go::score(Player player) const
{
    return 0.0f;
}

//Go Go::apply_move(Action& action) const
//{
//    return Go();
//}


Player Go::current_player() const
{
    return Player();
}

Player Go::next_player() const
{
    return Player();
}
