#pragma once
#include "Player.h"

class Map {
private:
	int gridSize;
	int worldX;
	int worldY;
	Player* myPlayer;
public:
	Map(Player* player, int size);
	~Map() {
		delete myPlayer;
	}
	void draw();
	Player* getPlayer();
};