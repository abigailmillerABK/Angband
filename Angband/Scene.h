/*
Author: Abigail Miller

Description:
Contains a list of all items in scene and controls their interactions with player
*/

#pragma once
#include <list>
#include <stdlib.h>
#include <time.h>
#include "Wall.h"
#include "Enemy.h"
#include "Buffer.h"
#include "Trinket.h"

class Scene {
private:
	int worldSize;
	Object* end = new Object(-1, -1); //Border
	Buffer* myBuffer;
	void drawWall(int xA,int yA, int xB, int yB) {
		for (int j = xA; j <= xB; j++) {
			for (int k = yA; k < yB; k++) {
				objList.push_back(new Wall(j, k));
			}
		}

	}

public:
	std::string event;
	Player* myPlayer = new Player(0, 0, worldSize);
	std::list<Object*> objList = {};
	Scene(int worldSize, Buffer* buffer) {
		myBuffer = buffer;
		this->worldSize = worldSize;
		objList.push_back(new Wall(2, 2));
		objList.push_back(new Wall(5, 8));
		objList.push_back(new Wall(5, 9));
		objList.push_back(new Wall(5, 10));
		objList.push_back(new Wall(8, 1));
		objList.push_back(new Wall(8, 2));
		drawWall(10,5,15,10);
		drawWall(20,20,28,28);
		objList.push_back(new Enemy(3, 3, worldSize));
		objList.push_back(new Enemy(5, 3, worldSize));
		objList.push_back(new Enemy(18, 3, worldSize));
		objList.push_back(new Enemy(20, 18, worldSize));
		objList.push_back(new Enemy(27, 20, worldSize));
		objList.push_back(new Trinket(8,8));
	}
	~Scene() {
		std::list<Object*>::iterator thisObject;
		for (thisObject = objList.begin(); thisObject != objList.end(); thisObject++) {
			delete (*thisObject);
			(*thisObject) = nullptr;
			objList.remove(*thisObject);
		}
	}

	void Refresh() //Tell all relevant object to act if they can
	{
		event = "";
		std::list<Object*>::iterator thisObject;
		for (thisObject = objList.begin(); thisObject != objList.end(); thisObject++) {
			if ((*thisObject)->myType == Object::type::Enemy) {
				Enemy* enemyPtr = static_cast<Enemy*>(*thisObject);
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
					if (isCollision(enemyPtr->GetX(), enemyPtr->GetY() - 1) == nullptr) {
						enemyPtr->Move(0, -1);
					}
					else if (isCollision(enemyPtr->GetX(), enemyPtr->GetY() - 1) == myPlayer) {
						enemyPtr->inFight = true;
					}
				}
				else if (cmd == "Right") {
					if (isCollision(enemyPtr->GetX(), enemyPtr->GetY() + 1) == nullptr) {
						enemyPtr->Move(0, 1);
					}
					else if (isCollision(enemyPtr->GetX(), enemyPtr->GetY() + 1) == myPlayer) {
						enemyPtr->inFight = true;
					}
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
		////Collision with object
		std::list<Object*>::iterator objPtr;
		for (objPtr = objList.begin(); objPtr != objList.end(); objPtr++) {
			if (x == (*objPtr)->GetX() && y == (*objPtr)->GetY()) {
				return &(**objPtr);
			}
		}
		return nullptr;
	}
};