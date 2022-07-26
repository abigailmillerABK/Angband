#pragma once
#include <string>
#include <list>
#include "Character.h"
#include "Trinket.h"


class Player : public Character{
private:
	std::list<Trinket*> itemList = {};

public:
	Player(int x, int y, int worldSize) :Character{x, y, worldSize}
	{
		myType = Object::type::Null;
		icon = "\033[94m@\033[94m";
		name = "Player";

		health = 100;
		attack = 5;
		defense = 12;
		speed = 6;
	}
	bool hasMoved;

	void addItem(Trinket* newItem) {
		itemList.push_back(newItem);
	}
	void useItem(Trinket* targetItem) {
		itemList.remove(targetItem);
	}
};