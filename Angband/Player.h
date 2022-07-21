#pragma once
#include <string>
#include "Object.h"
#include "Character.h"


class Player : public Character{

public:
	Player(int x, int y, int worldSize) :Character{ x, y, worldSize}
	{
		thisObject = "t_Null";
		icon = "\033[94m@\033[94m";

		health = 500;
		attack = 100;
		defense = 100;
		speed = 6;
	}
};