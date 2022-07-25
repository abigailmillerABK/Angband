#include <conio.h>
#include <iostream>;
#include "Map.h"
#include "Player.h"
#include "Scene.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void main() {

	int mapSize = 20;
	int worldSize = 30;

	Scene* thisScene = new Scene(worldSize);
	Map myMap = Map(thisScene->myPlayer, thisScene, mapSize, worldSize);

	myMap.draw();

	//Check input
	char keyPress = _getch();
	//int keyVal = keyPress;

	while (true) {
		switch (_getch()) {
		case KEY_UP:
			if (thisScene->isCollision(thisScene->myPlayer->GetX() - 1, thisScene->myPlayer->GetY()) == nullptr){
				thisScene->myPlayer->Move(-1, 0);
			}
			thisScene->Refresh();
			myMap.draw();
			break;
		case KEY_DOWN:
			if (thisScene->isCollision(thisScene->myPlayer->GetX() + 1, thisScene->myPlayer->GetY()) == nullptr) {
				thisScene->myPlayer->Move(1, 0);
			}
			thisScene->Refresh();
			myMap.draw();
			break;
		case KEY_RIGHT:
			if (thisScene->isCollision(thisScene->myPlayer->GetX(), thisScene->myPlayer->GetY() + 1) == nullptr) {
				thisScene->myPlayer->Move(0, 1);
			}
			thisScene->Refresh();
			myMap.draw();
			break;
		case KEY_LEFT:
			if (thisScene->isCollision(thisScene->myPlayer->GetX(), thisScene->myPlayer->GetY() - 1) == nullptr) {
				thisScene->myPlayer->Move(0, -1);
			}
			thisScene->Refresh();
			myMap.draw();
			break;
		}
		std::cout << "\n\nAn event happens!!!";
	}
};