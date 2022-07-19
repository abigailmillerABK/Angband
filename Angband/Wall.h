#pragma once
#include "Object.h"

class Wall : public Object {
public:
	Wall() {
		thisObject = t_Wall;
	}
};