#pragma once
#include "Object.h"
#include <list>
#include "Wall.h"
#include "Character.h"
//#include "Enemy.h"

class Scene {
public:
	std::list<Object> objList = {};
	Scene(int worldSize) {
		objList.push_back(Wall(2, 2));
		//Enemy e = Enemy(3, 3, this, worldSize, "Elf");
	}
	void Refresh(); //Tell all relevant object to act if they can
};