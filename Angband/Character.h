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
	bool inFight;
	bool isAlive;
	std::string name;

	Character(int x, int y, int worldSize) : Object{ x,y } 
	{
		this->worldSize = worldSize;
		health = 100;
		attack = 3;
		defense = 10;
		speed = 5;
	}
	std::string Fight(Character* target) {
		std::string event = "";
		target->inFight = true;
		bool hit = (((rand() % 20) + 1) + this->getAttack()) - target->getDefense() > 0;
		event += "\nThe " + name + " swings to attack";
		if (hit) {
			int dmg = ((rand() % 8) + 1) + this->getAttack();
			event += "\nThe " + name + " does " + std::to_string(dmg) + " damage";
			target->addHealth(-dmg);
			event += "\n" + target->name + " health is now at " + std::to_string(target->getHealth()) + "hp";
		}
		else {
			event += "\nThe " + name + " misses";
		}
		return event;
	}
	std::string getRace() {
		return myRace;
	};
	void newRandom() {
		//random race
		std::string races[6] = { "Orc", "Rat", "Ooze", "Elf", "Halfling", "Skeleton"};
		std::string titles[6] = { "conniving", "drooling", "shadowy", "reckless","unlawful","suspicious"};
		std::string myRace = races[rand() % 6];
		icon = myRace[0];
		std::string title = titles[rand() % 6];
		name = "a " + title + " " + myRace;
		//random name
	}
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
	void setSpeed(int newSpeed) {
		speed = newSpeed;
	}
	void addHealth(int add) {
		if (add > 0 && health < 100) {
			health += add;
			if (health > 100) {
				health = 100;
			}
			return;
		}
		if (add < 0 && health > 0) {
			health += add;
			if (health < 0) {
				health = 0;
			}
			return;
		}
	}

	void Move(int x, int y) override{
		//Check for collision
		int moveX = worldX + x;
		int moveY = worldY + y;

		worldX = moveX;
		worldY = moveY;
	};
};