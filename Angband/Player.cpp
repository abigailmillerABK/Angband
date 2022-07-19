#include "Player.h"

//Player::Player()
//{
//	this->worldX = 0;
//	this->worldY = 0;
//	this->icon = "\033[94mP\033[94m";
//}

Player::Player(int size)
{
	this->worldX = size / 2;
	this->worldY = size / 2;
	this->icon = "\033[94mP\033[94m";
}

void Player::move(int x, int y)
{
	this->worldX += x;
	this->worldY += y;
}

