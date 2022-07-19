#pragma once
#include "Object.h"
#include <list>
#include "Wall.h"
#include "Character.h"

class Scene {
public:
	std::list<Object> objList = {};
	Scene() {
		Wall w = Wall(2,2);
	}
};