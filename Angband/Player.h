#pragma once
#include <string>
#include <list>
#include "Character.h"
#include "Item.h"


class Player : public Character{
private:
	Object* obj = new Object(5, 5);
	Item* thisItem = new Item(0, 0);
	//std::list<Item> itemList = {};

public:
	Player(int x, int y, int worldSize) :Character{ x, y, worldSize}
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

	//void addItem(Item* newItem);
};