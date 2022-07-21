#pragma once
#include <iostream>

class Object {
protected:
	int worldX;
	int worldY;
	std::string thisObject;
public:
	Object(int x, int y) {
		worldX = x;
		worldY = y;
		icon = "X";
	}
	std::string icon;
	int GetX();
	int GetY();
};