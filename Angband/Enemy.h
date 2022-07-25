#pragma once
#include "Object.h"
#include "Character.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>


class Enemy : public Character {

public:
	Enemy(int x, int y, int worldSize) :Character{ x, y, worldSize }
	{
		thisObject = "t_Enemy";
		icon = "\u001b[31mA\u001b[31m";
	}
	std::string Act() {
		srand(time(NULL));
		//Move in random direction
		char directions[4] = { 'u', 'd', 'l', 'r'};
		int random = rand() % 4;
		char myDirection = directions[random];

		switch (myDirection) {
		case 'u':
			return "Up";
		case 'd':
			return "Down";
		case 'l':
			return "Left";
		case 'r':
			return "Right";
		}
	}
};