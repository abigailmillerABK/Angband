#include "Player.h"

Player::Player(int size)
{
	thisObject = t_Null;
	worldX = size / 2;
	worldY = size / 2;
	icon = "\033[94mP\033[94m";

	health = 500;
	attack = 100;
	defense = 100;
	speed = 6;
}

