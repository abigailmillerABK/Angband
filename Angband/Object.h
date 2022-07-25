#pragma once
#include <iostream>
#include <string.h>

class Object {
protected:
	int worldX;
	int worldY;
public:	
	std::string thisObject;
	Object(int x, int y) {
		worldX = x;
		worldY = y;
		//icon = "";
	}
	bool operator == (const Object& other) const {
		if (this->worldX == other.worldX) {
			if (this->worldY == other.worldY) {
				return true;
			}
		}
		return false;
	}
	std::string icon;
	int GetX();
	int GetY();
	virtual std::string Act() { return " "; };
	virtual void Move(int x, int y) {};
};