/*
Author: Abigail Miller

Description:
An Object that contains randomly generated attributes
*/

#include "Trinket.h"
#include "Character.h"

Trinket::Trinket(int x, int y) : Object(x, y) {
	icon = "\u001b[33mi\u001b[33m";
	myType = Object::type::Item;
	randomize();
}
void Trinket::randomize() {
	std::string nameList[5] = { "glorious","nifty","totally unique","lovely","rad" };
	std::string typeList[5] = { "Sword","Book","Potion","Wand", "Mirror" };
	std::string useList[4] = { "healing","destruction","general coolness","entanglement" };

	name = nameList[rand() % 5];
	type = typeList[rand() % 4];
	use = useList[rand() % 4];
	title = name + " " + type + " of " + use;

	value = 10;
}
void Trinket::useOn(Character* target) {
	if (use == "healing") {
		target->addHealth(value);
	}
	else if (use == "destruction") {
		target->addHealth(-value);
	}
	else if (use == "general coolness") {
		target->name = "the cool " + target->name;
	}
	else if (use == "entanglement") {
		target->setSpeed(0);
	}
}