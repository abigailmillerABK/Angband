/*
Author: Abigail Miller
*/

#pragma once
#include "Player.h"
#include "Scene.h"

class Map {
private:
	int gridSize;
	int worldSize;
	int worldX;
	int worldY;
	Player* myPlayer;
	Scene* myScene;
	void ReCenter();
public:
	Map(Player* player, Scene* scene, int gridSize, int worldSize);
	void draw();
	Player* getPlayer();
};