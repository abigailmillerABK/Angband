#include <conio.h>
#include <iostream>;
#include "Map.h"
#include "Player.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void main() {

	int mapSize = 20;

	Player* myPlayer = new Player(mapSize);
	Map myMap = Map(myPlayer, mapSize);

	myMap.draw();

	//Check input
	char keyPress = _getch();
	//int keyVal = keyPress;

	while (true) {
		switch (_getch()) {
		case KEY_UP:
			myPlayer->move(-1, 0);
			myMap.draw();
			break;
		case KEY_DOWN:
			myPlayer->move(1, 0);
			myMap.draw();
			break;
		case KEY_RIGHT:
			myPlayer->move(0, 1);
			myMap.draw();
			break;
		case KEY_LEFT:
			myPlayer->move(0, -1);
			myMap.draw();
			break;
		}
	}
};