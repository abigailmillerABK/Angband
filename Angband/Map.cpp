#include "Map.h"
#include <iostream>
#include "Scene.h"
#include <iterator>

void Map::ReCenter()
{
	worldX = myPlayer->GetX() - gridSize/2;
	worldY = myPlayer->GetY() - gridSize/2;
}

Map::Map(Player* player, Scene* scene, int gridSize, int worldSize)
{
	worldX = gridSize;
	worldY = gridSize;
	this->gridSize = gridSize;
	this->worldSize = worldSize;

	myPlayer = player;
	myScene = scene;
}

void Map::draw()
{
	std::cout << "\033[2J\033[1;1H"; //Clear screen
	system("CLS");
	//Draw screen
	ReCenter();
	for (int j = worldX; j < (worldX + gridSize); j++) {
		for (int k = worldY; k < (gridSize+worldY); k++) {
			//Check whether matched with coordinates of object/character
			std::list<Object>::iterator listPtr;
			bool isIcon = false;
			for (listPtr = myScene->objList.begin(); listPtr != myScene->objList.end(); listPtr++) {
				if (j == listPtr->GetX() && k == listPtr->GetY()) {
					std::cout <<listPtr->icon;
					isIcon = true;
				}
			}
			if (j == myPlayer->GetX() && k == myPlayer->GetY()) {
				std::cout << myPlayer->icon;
				isIcon = true;
			}
			//Check whether outside world boundaries
			if (j<0 or j>worldSize or k<0 or k>worldSize) {
				std::cout << "\033[37mX\033[37m";
				isIcon = true;
			}
			if (isIcon == false) {
				std::cout << "\033[37m \033[37m";
			}
		}
		std::cout << "\n";
	}
}

Player* Map::getPlayer() {
	return myPlayer;
}
