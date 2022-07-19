#pragma once
#include "Object.h"

class Wall : public Object {
public:
	Wall() {
		thisObject = t_Wall;
		icon = "\033[33mw\033[33m";
	}
};