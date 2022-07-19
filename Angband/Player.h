#pragma once
#include <string>
#include "Object.h"

class Player : public Object{

public:
	Player(int size);
	void move(int x, int y);
};