/*
Author: Abigail Miller
*/

#pragma once
#include "Object.h"

class Wall : public Object {
public:
	Wall(int x, int y) : Object{ x,y }
	 {
		myType = Object::type::Wall;
		icon = "\033[37mx\033[37m";
	}
};