#pragma once
#include <iostream>

class Object {
protected:
	int worldX;
	int worldY;
public:
	std::string icon;
	int getX();
	int getY();
};