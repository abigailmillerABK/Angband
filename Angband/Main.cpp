/*
Author: Abigail Miller

Description:
Move using arrow keys
Run into red icons to fight enemies
Move over yellow icons to collect tokens
*/

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include "Map.h"
#include "Player.h"
#include "Scene.h"
#include "Buffer.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ZERO 48
#define KEY_ONE 49
#define KEY_TWO 50
#define KEY_THREE 51

//Function provided by http://www.codeincodeblock.com/2011/03/move-console-windows-using-codeblock.html

void redraw(Scene* thisScene, Map myMap, Buffer* myBuffer) {
	std::cout << "\033[2J\033[1;1H"; //Clear screen
	system("CLS");
	thisScene->Refresh();
	myBuffer->DrawOptions(thisScene->myPlayer);
	myBuffer->Print(Buffer::textBlock::options);
	myMap.draw();
	myBuffer->Print(Buffer::textBlock::events);
}

void interact(int x, int y, Object* target, Scene* thisScene, Buffer* myBuffer, Player* myPlayer) {
	if (target == nullptr) {
		thisScene->myPlayer->Move(x, y);
		thisScene->myPlayer->hasMoved = true;
	}
	else {
		if (target->myType == Object::type::Enemy ) {
			Enemy* thisEnemy = static_cast<Enemy*>(target);
			myBuffer->AddText(Buffer::textBlock::events, thisScene->myPlayer->Fight(thisEnemy));
			if (thisEnemy->getHealth() == 0) {
				myBuffer->AddText(Buffer::textBlock::events, "\n" + thisEnemy->name + " has been slain");
				thisScene->objList.remove(thisEnemy);
			}
		}
		if (target->myType == Object::type::Item) {
			Trinket* thisItem = static_cast<Trinket*>(target);
			myBuffer->AddText(Buffer::textBlock::events, "You have found an item!\n");
			myPlayer->addItem(thisItem);
			thisScene->objList.remove(thisItem);
			myBuffer->AddText(Buffer::textBlock::events, "You quickly pocket the " + thisItem->title);
		}
	}
}

void main() {
	srand(time(NULL));

//Set up console size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, 0, 0, 400, 800, TRUE);

	int mapSize = 15;
	int worldSize = 30;

	Buffer* myBuffer = new Buffer();
	Scene* thisScene = new Scene(worldSize, myBuffer);
	Map myMap = Map(thisScene->myPlayer, thisScene, mapSize, worldSize);

	myMap.draw();

	//Check input;
	Object* target;
	//int keyVal = keyPress;

	while (_getch()!= KEY_ESC) {
		thisScene->myPlayer->hasMoved = true;
		switch (_getch()) {
		case KEY_UP:
			myBuffer->Clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX() - 1, thisScene->myPlayer->GetY());
			interact(-1, 0, target, thisScene, myBuffer, thisScene->myPlayer);
			redraw(thisScene, myMap, myBuffer);
			break;
		case KEY_DOWN:
			myBuffer->Clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX() + 1, thisScene->myPlayer->GetY());
			interact(1, 0, target, thisScene, myBuffer, thisScene->myPlayer);
			redraw(thisScene, myMap, myBuffer);
			break;
		case KEY_RIGHT:
			myBuffer->Clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX(), thisScene->myPlayer->GetY() + 1);
			interact(0, 1, target, thisScene, myBuffer, thisScene->myPlayer);
			redraw(thisScene, myMap, myBuffer);
			break;
		case KEY_LEFT:
			myBuffer->Clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX(), thisScene->myPlayer->GetY() - 1);
			interact(0, -1, target, thisScene, myBuffer, thisScene->myPlayer);
			redraw(thisScene, myMap, myBuffer);
			break;
		
		case KEY_ZERO:
			myBuffer->Clear();
			myBuffer->SelectOption(0,thisScene->myPlayer);
			redraw(thisScene, myMap, myBuffer);
			break;

		default:
			break;
		}
		
	}
	system("CLS");
	std::cout << "THANK YOU FOR PLAYING!!!\n";
};