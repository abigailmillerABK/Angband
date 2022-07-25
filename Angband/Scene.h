#pragma once
#include "Object.h"
#include <list>
#include "Wall.h"
#include "Character.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "Buffer.h"
#include "Item.h"

class Scene {
private:
	int worldSize;
	Object* end = new Object(-1, -1); //Border
	Buffer* myBuffer;
	void drawWall(int xA,int yA, int xB, int yB) {
		for (int j = xA; j <= xB; j++) {
			for (int k = yA; k < yB; k++) {
				objList.push_back(Wall(j, k));
			}
		}

	}

public:
	std::string event;
	Player* myPlayer = new Player(0, 0, worldSize);
	std::list<Object> objList = {};
	std::list<Enemy> enemyList = {};
	std::list<Item> itemList = {};
	Scene(int worldSize, Buffer* buffer) {
		myBuffer = buffer;
		this->worldSize = worldSize;
		objList.push_back(Wall(2, 2));
		objList.push_back(Wall(5, 8));
		objList.push_back(Wall(5, 9));
		objList.push_back(Wall(5, 10));
		objList.push_back(Wall(8, 1));
		objList.push_back(Wall(8, 2));
		drawWall(10,5,15,10);
		drawWall(20,20,28,28);
		enemyList.push_back(Enemy(3, 3, worldSize));
		enemyList.push_back(Enemy(5, 3, worldSize));
		enemyList.push_back(Enemy(18, 3, worldSize));
		enemyList.push_back(Enemy(20, 18, worldSize));
		enemyList.push_back(Enemy(27, 20, worldSize));
		itemList.push_back(Item(8,8));
	}

	void Refresh() //Tell all relevant object to act if they can
	{
		event = "";
		std::list<Enemy>::iterator enemyPtr;
		for (enemyPtr = enemyList.begin(); enemyPtr != enemyList.end(); enemyPtr++) {
				std::string cmd = enemyPtr->Act();
				//Combat
				if (cmd == "Fight") {					
					//If next to player, hit
					if (myPlayer->hasMoved == false) {
						myBuffer->addText(enemyPtr->Fight(myPlayer));
					}
					//if not next to player, pursue
					else {
						if (myPlayer->GetX() < enemyPtr->GetX() - 1) {
							cmd = "Up";
						}
						else if (myPlayer->GetX() > enemyPtr->GetX() + 1) {
							cmd = "Down";
						}
						else if (myPlayer->GetY() > enemyPtr->GetY() - 1) {
							cmd = "Right";
						}
						else if (myPlayer->GetY() < enemyPtr->GetY() + 1) {
							cmd = "Left";
						}
					}
				}
				//Movement
				if (cmd == "Up") {
					if (isCollision(enemyPtr->GetX() - 1, enemyPtr->GetY()) == nullptr) {
						enemyPtr->Move(-1, 0);
					}
					else if (isCollision(enemyPtr->GetX() - 1, enemyPtr->GetY()) == myPlayer) {
						enemyPtr->inFight = true;
					}
				}
				else if (cmd == "Down") {
					if (isCollision(enemyPtr->GetX() + 1, enemyPtr->GetY()) == nullptr) {
						enemyPtr->Move(1, 0);
					}
					else if (isCollision(enemyPtr->GetX() + 1, enemyPtr->GetY()) == myPlayer) {
						enemyPtr->inFight = true;
					}
				}
				else if (cmd == "Left") {
					if (isCollision(enemyPtr->GetX(), enemyPtr->GetY()-1)==nullptr) {
						enemyPtr->Move(0, -1);
					}
					else if (isCollision(enemyPtr->GetX(), enemyPtr->GetY() - 1) == myPlayer) {
						enemyPtr->inFight = true;
					}
				}
				else if (cmd == "Right") {
					if (isCollision(enemyPtr->GetX(), enemyPtr->GetY()+1)==nullptr) {
						enemyPtr->Move(0, 1);
					}
					else if (isCollision(enemyPtr->GetX(), enemyPtr->GetY() + 1) == myPlayer) {
						enemyPtr->inFight = true;
					}
				}
		}
	}
	Object* isCollision(int x, int y) {
		std::list<Object>::iterator listPtr;
		//Collision with border
		if (x < 0 || x > worldSize || y < 0 || y > worldSize) {
			return end;
		}
		//Collision with player
		if (x == myPlayer->GetX() && y == myPlayer->GetY()) {
			return myPlayer;
		}
		//Collision with wall
		for (listPtr = objList.begin(); listPtr != objList.end(); listPtr++) {
			if (x == listPtr->GetX() && y == listPtr->GetY()) {
				return &(*listPtr);
			}
		}
		//Collision with enemy
		std::list<Enemy>::iterator enemPtr;
		for (enemPtr = enemyList.begin(); enemPtr != enemyList.end(); enemPtr++) {
			if (x == enemPtr->GetX() && y == enemPtr->GetY()) {
				return &(*enemPtr);
			}
		}
		return nullptr;
	}
};