#include "Map.h"
#include <iostream>

Map::Map(Player* player, int size)
{
	worldX = size;
	worldY = size;
	gridSize = size;

	myPlayer = player;
}

void Map::draw()
{
	std::cout << "\033[2J\033[1;1H"; //Clear screen
	system("CLS");
	//Draw screen
	for (int j = 0; j < gridSize; j++) {
		for (int k = 0; k < gridSize; k++) {
			//Check whether matched with coordinates of object/character
			if (j == myPlayer->getX() && k == myPlayer->getY()) {
				std::cout << " " << myPlayer->icon << " ";
			}
			else {
				std::cout << "\033[37m   \033[37m";
			}
		}
		std::cout << "\n";
	}
}

Player* Map::getPlayer() {
	return myPlayer;
}
