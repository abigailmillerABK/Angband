/*
Author: Abigail Miller

Description:
Refresh all relevant object positions and redraw
*/

#include "Map.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "Scene.h"
#include <iterator>
#include <stdlib.h>
#include <time.h>

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
	//Draw screen
	ReCenter();
	int gridX = gridSize;
	int gridY = gridSize * 2; //To square out the view
	for (int j = worldX; j < (worldX + gridX); j++) {
		for (int k = worldY; k < (gridY+worldY); k++) {
			//Check whether matched with coordinates of object/character
			std::list<Object*>::iterator objectPtr;
			std::list<Enemy>::iterator enemyPtr;
			bool isIcon = false;
			if (isIcon == false) {
				for (const Object* objectPtr : myScene->objList) //Use this FOR loop
				{
					if (j == objectPtr->GetX() && k == objectPtr->GetY()) {
						std::cout << objectPtr->icon;
						isIcon = true;
						break;
					}
				}
			}
			if (j == myPlayer->GetX() && k == myPlayer->GetY()) {
				std::cout << myPlayer->icon;
				isIcon = true;
			}
			//Check whether outside world boundaries
			if (j<0 || j>worldSize || k<0 || k>worldSize) {
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
