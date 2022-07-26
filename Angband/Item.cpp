#include "Item.h"

Item::Item(int x, int y) : Object(x, y) {
	icon = "\u001b[33mi\u001b[33m";
	randomize();
}
void Item::randomize() {
	std::string nameList[5] = { "glorious","nifty","totally unique","lovely","rad" };
	std::string typeList[5] = { "Sword","Book","Potion","Wand", "Mirror" };
	std::string useList[4] = { "healing","destruction","general coolness","entanglement" };

	name = nameList[rand() % 5];
	type = typeList[rand() % 4];
	use = useList[rand() % 4];
	title = name + " " + type + " of " + use;

	value = 10;
}
void Item::useOn(Character* target) {
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