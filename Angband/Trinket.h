#pragma once
#include <string>
#include "Object.h"
#include "Character.h"

class Trinket : public Object{
 private:
	std::string name;
	std::string type;
	std::string use;
	int value;

public:
	std::string title;
	Trinket(int x, int y);
	void randomize();
	void useOn(Character* target);
};