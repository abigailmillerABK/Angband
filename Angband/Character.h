#pragma once
#include "Object.h"
#include "Scene.h"

class Character : public Object{

protected:
	std::string myRace;
	int health;
	int attack;
	int defense;
	int speed;

	int worldSize;

	Scene* myScene;

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

	void move(int x, int y) {
		//Check for collision
		int moveX = worldX + x;
		int moveY = worldY + y;

		//std::list<Object>::iterator listPtr;
		//for (listPtr = myScene->objList.begin(); listPtr != myScene->objList.end(); listPtr++) {
		//	if (moveX == listPtr->GetX() && moveY == listPtr->GetY()) {
		//		return; //No overlaps with other objects
		//	}
		//	else if (moveX < 0 || moveX > worldSize || moveY < 0 || moveY > worldSize) {
		//		return;
		//	}
		//}

		worldX = moveX;
		worldY = moveY;
	};
};