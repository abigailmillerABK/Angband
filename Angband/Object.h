/*
Author: Abigail Miller

Description:
an Object stores or changes their X and Y values
*/

#pragma once
#include <iostream>
#include <string.h>

class Object {
protected:
	int worldX;
	int worldY;
public:	
	enum type { Enemy, Item, Wall, Null };
	type myType;
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
	int GetX() const;
	int GetY() const;
	virtual std::string Act() { return " "; };
	virtual void Move(int x, int y) {};
};