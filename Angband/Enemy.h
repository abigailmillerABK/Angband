#pragma once
#include "Character.h"


class Enemy : public Character {

public:

	Enemy(int x, int y, int worldSize) :Character{ x, y, worldSize }
	{
		myType = Object::type::Enemy;
		newRandom();
		icon = "\u001b[31m"+icon+"\u001b[31m";
		inFight = false;
		isAlive = true;
		
	}
	std::string Act() {
		if (inFight == false){
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
		else { //Fight
			return "Fight";
		}
	}
};