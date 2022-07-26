#include <conio.h>
#include <iostream>;
#include "Map.h"
#include "Player.h"
#include "Scene.h"
#include "Buffer.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void redraw(Scene* thisScene, Map myMap, Buffer* myBuffer) {
	thisScene->Refresh();
	myMap.draw();
	myBuffer->print();
}

void interact(int x, int y, Object* target, Scene* thisScene, Buffer* myBuffer) {
	if (target == nullptr) {
		thisScene->myPlayer->Move(x, y);
		thisScene->myPlayer->hasMoved = true;
	}
	else {
		if (target->myType == Object::type::Enemy ) {
			Enemy* thisEnemy = static_cast<Enemy*>(target);
			myBuffer->addText(thisScene->myPlayer->Fight(thisEnemy));
			if (thisEnemy->getHealth() == 0) {
				myBuffer->addText("\n" + thisEnemy->name + " has been slain");
				thisScene->objList.remove(thisEnemy);
			}
		}
		if (target->myType == Object::type::Item) {

		}
	}
}

void main() {
	srand(time(NULL));

	int mapSize = 20;
	int worldSize = 30;

	Buffer* myBuffer = new Buffer();
	Scene* thisScene = new Scene(worldSize, myBuffer);
	Map myMap = Map(thisScene->myPlayer, thisScene, mapSize, worldSize);

	myMap.draw();

	//Check input
	char keyPress = _getch();
	Object* target;
	//int keyVal = keyPress;

	while (true) {
		
		thisScene->myPlayer->hasMoved = false;
		switch (_getch()) {
		case KEY_UP:
			myBuffer->clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX() - 1, thisScene->myPlayer->GetY());
			interact(-1, 0, target, thisScene, myBuffer);
			redraw(thisScene, myMap, myBuffer);
			break;
		case KEY_DOWN:
			myBuffer->clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX() + 1, thisScene->myPlayer->GetY());
			interact(1, 0, target, thisScene, myBuffer);
			redraw(thisScene, myMap, myBuffer);
			break;
		case KEY_RIGHT:
			myBuffer->clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX(), thisScene->myPlayer->GetY() + 1);
			interact(0, 1, target, thisScene, myBuffer);
			redraw(thisScene, myMap, myBuffer);
			break;
		case KEY_LEFT:
			myBuffer->clear();
			target = thisScene->isCollision(thisScene->myPlayer->GetX(), thisScene->myPlayer->GetY() - 1);
			interact(0, -1, target, thisScene, myBuffer);
			redraw(thisScene, myMap, myBuffer);
			break;
		}
	}
};