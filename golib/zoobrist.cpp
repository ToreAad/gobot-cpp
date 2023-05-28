#include "zoobrist.h"

unsigned long long int Zoobrist::get_zoobrist_hash(int row, int col, Player player)
{
	int PLAYER_SIZE = 3;
	return _ZOOBRIST_ARRAY[PLAYER_SIZE * (row * _BOARD_SIZE + col) + player];
}

