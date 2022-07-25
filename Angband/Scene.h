#pragma once
#include "Object.h"
#include <list>
#include "Wall.h"
#include "Character.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "Buffer.h"

class Scene {
private:
	int worldSize;
	Object* end = new Object(-1, -1); //Border
	Buffer* myBuffer;

public:
	std::string event;
	Player* myPlayer = new Player(0, 0, worldSize);
	std::list<Object> objList = {};
	std::list<Enemy> enemyList = {};
	Scene(int worldSize, Buffer* buffer) {
		myBuffer = buffer;
		this->worldSize = worldSize;
		objList.push_back(Wall(2, 2));
		objList.push_back(Wall(5, 8));
		objList.push_back(Wall(5, 9));
		objList.push_back(Wall(5, 10));
		objList.push_back(Wall(8, 1));
		objList.push_back(Wall(8, 2));
		objList.push_back(Wall(8, 3));
		enemyList.push_back(Enemy(3, 3, worldSize));
	}
	void Refresh() //Tell all relevant object to act if they can
	{
		event = "";
		std::list<Enemy>::iterator listPtr;
		for (listPtr = enemyList.begin(); listPtr != enemyList.end(); listPtr++) {
				std::string cmd = listPtr->Act();
				//Combat
				if (cmd == "Fight") {					
					//If next to player, hit
					if (myPlayer->hasMoved == false) {
						myBuffer->addText(listPtr->Fight(myPlayer));
					}
					//if not next to player, pursue
					else {
						if (myPlayer->GetX() < listPtr->GetX() - 1) {
							cmd = "Up";
						}
						else if (myPlayer->GetX() > listPtr->GetX() + 1) {
							cmd = "Down";
						}
						else if (myPlayer->GetY() > listPtr->GetY() - 1) {
							cmd = "Right";
						}
						else if (myPlayer->GetY() < listPtr->GetY() + 1) {
							cmd = "Left";
						}
					}
				}
				//Movement
				if (cmd == "Up") {
					if (isCollision(listPtr->GetX() - 1, listPtr->GetY()) == nullptr) {
						listPtr->Move(-1, 0);
					}
					else if (isCollision(listPtr->GetX() - 1, listPtr->GetY()) == myPlayer) {
						listPtr->inFight = true;
					}
				}
				else if (cmd == "Down") {
					if (isCollision(listPtr->GetX() + 1, listPtr->GetY()) == nullptr) {
						listPtr->Move(1, 0);
					}
					else if (isCollision(listPtr->GetX() + 1, listPtr->GetY()) == myPlayer) {
						listPtr->inFight = true;
					}
				}
				else if (cmd == "Left") {
					if (isCollision(listPtr->GetX(), listPtr->GetY()-1)==nullptr) {
						listPtr->Move(0, -1);
					}
					else if (isCollision(listPtr->GetX(), listPtr->GetY() - 1) == myPlayer) {
						listPtr->inFight = true;
					}
				}
				else if (cmd == "Right") {
					if (isCollision(listPtr->GetX(), listPtr->GetY()+1)==nullptr) {
						listPtr->Move(0, 1);
					}
					else if (isCollision(listPtr->GetX(), listPtr->GetY() + 1) == myPlayer) {
						listPtr->inFight = true;
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