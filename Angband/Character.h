#pragma once
#include "Object.h"

class Character : public Object{

protected:
	std::string myRace;
	int health;
	int attack;
	int defense;
	int speed;

	int worldSize;

public:
	Character(int x, int y, int worldSize) : Object{ x,y } 
	{
		this->worldSize = worldSize;
	}
	std::string getRace() {
		return myRace;
	};
	int getHealth() {
		return health;
	}
	int getAttack() {
		return attack;
	}
	int getDefense() {
		return defense;
	}
	int getSpeed() {
		return speed;
	}

	void Move(int x, int y) override{
		//Check for collision
		int moveX = worldX + x;
		int moveY = worldY + y;

		worldX = moveX;
		worldY = moveY;
	};
};