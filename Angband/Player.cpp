#include "Player.h"

//Player::Player()
//{
//	this->worldX = 0;
//	this->worldY = 0;
//	this->icon = "\033[94mP\033[94m";
//}

Player::Player(int size)
{
	thisObject = t_Null;
	this->worldX = size / 2;
	this->worldY = size / 2;
	this->icon = "\033[94mP\033[94m";

	health = 500;
	attack = 100;
	defense = 100;
	speed = 6;
}

