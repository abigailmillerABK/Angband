#pragma once
#include "Object.h"
#include "Character.h"

class Item : public Object {
private:
	std::string title;
	std::string name;
	std::string type;
	std::string use;
	int value;

public:
	Item(int x, int y);
	void randomize();
	void useOn(Character* target);
};