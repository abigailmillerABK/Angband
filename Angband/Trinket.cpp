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
	if (use == "healing") {
		thisEffect = heal;
	}
	else if (use == "destruction") {
		thisEffect = harm;
	}
	else if (use == "general coolness") {
		thisEffect = cool;
	}
	else if (use == "Entanglement") {
		thisEffect = slow;
	}
	title = name + " " + type + " of " + use;

	value = 10;
}
std::string Trinket::useOn(Character* target) {
	if (thisEffect == heal) {
		target->addHealth(value);
		return (target->name+ " gains " + std::to_string(value) + " hp.");
	}
	else if (thisEffect == harm) {
		target->addHealth(-value);
		return (target->name + " loses " + std::to_string(value) + " hp.");
	}
	else if (thisEffect == cool) {
		target->name = " the cool " + target->name;
		return (target->name + " is now super cool.");
	}
	else if (thisEffect == slow) {
		target->setSpeed(0);
		return (target->name + " can no longer seem to move");
	}
}