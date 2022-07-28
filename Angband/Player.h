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

public:
	int numItems = 0;
	Trinket* itemList[5];
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
		itemList[numItems] = newItem;
		numItems++;
	}
	std::string useItem(int itemNumber, Character* target) {
		return itemList[itemNumber]->useOn(target);
		numItems--;
		//refactor list
	}
};