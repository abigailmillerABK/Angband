/*
Author: Abigail Miller

Description:
The player is extended from Character and it contains a list of held items
*/

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
	void useItem(int itemNumber, Character* target) {
		std::list<Trinket*>::iterator itemPtr;
		int i = 0;
		for (itemPtr = itemList.begin(); i == itemNumber; itemPtr++, i++) {
			itemList.remove(*(itemPtr));
		}
	}
	std::list<Trinket*> ListItems() {
		return itemList;
	}
};