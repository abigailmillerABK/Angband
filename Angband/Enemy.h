#pragma once
#include "Character.h"

class Enemy : public Character {
	Enemy(race newRace) {
		thisObject = t_Enemy;
		myRace = newRace;
		switch(myRace) {
		case Human:
			health = 100;
			attack = 50;
			defense = 50;
			speed = 3;
			break;
		case Elf:
			health = 100;
			attack = 50;
			defense = 50;
			speed = 3;
			break;
		case Dwarf:
			health = 100;
			attack = 50;
			defense = 50;
			speed = 3;
			break;
		case Goblin:
			health = 100;
			attack = 50;
			defense = 50;
			speed = 3;
			break;
		case Orc:
			health = 100;
			attack = 50;
			defense = 50;
			speed = 3;
			break;
		case Giant:
			health = 100;
			attack = 50;
			defense = 50;
			speed = 3;
			break;
		default:
			break;
		}
	}
};