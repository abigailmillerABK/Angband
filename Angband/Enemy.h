#pragma once
#include <string>
#include "Object.h"
#include "Character.h"

class Enemy{ : public Character {

public:
	Enemy(int x, int y,int worldSize) :Character{ x, y,worldSize }
	{
	}
};