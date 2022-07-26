#pragma once
#include <string>
#include "Object.h"
#include "Character.h"


class Player : public Character{

public:
	Player(int x, int y, int worldSize) :Character{ x, y, worldSize}
	{
		myType = Object::type::Null;
		icon = "\033[94m@\033[94m";
		name = "Player";

		health = 100;
		attack = 5;
		defense = 12;
		speed = 6;
	}
	bool hasMoved;
};