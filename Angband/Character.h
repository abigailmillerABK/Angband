#pragma once
#include "Object.h"

class Character : public Object{
protected:
	enum race { Human, Elf, Dwarf, Goblin, Orc, Giant };
	race myRace;
	int health;
	int attack;
	int defense;
	int speed;

public:
	race getRace() {
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

	void move(int x, int y) {
		worldX += x;
		worldY += y;
	};
};