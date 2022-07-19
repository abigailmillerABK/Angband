#pragma once
#include <iostream>

class Object {
protected:
	int worldX;
	int worldY;
	enum ObjectType {t_Wall,t_Enemy,t_Item,t_NPC, t_Null};
	ObjectType thisObject;
public:
	std::string icon;
	int getX();
	int getY();
};