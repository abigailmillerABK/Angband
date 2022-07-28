/*
Author: Abigail Miller

Description:
Stores and prints all relevant text to screen in an orderly fashion.
*/

#pragma once
#include <string>
#include <iostream>
#include "Player.h"
#include "Trinket.h"

class Buffer {
private:
	std::string eventsText;
	std::string optionsText;
	int itemNum;

public:
	enum textBlock {events, options};
	enum Menu {itemMenu, targetMenu};
	Menu myMenu = itemMenu;
	void AddText(textBlock t, std::string newText) {
		if (t == events) {
			eventsText += newText;
		}
		else if (t == options) {
			optionsText += newText;
		}
	}
	void Clear() {
		eventsText = "";
		optionsText = "";
	}
	void Print(textBlock t) {
		if (t == events) {
			if (eventsText != "") {
				std::cout << "\n****************************************\n";
				std::cout << eventsText;
				std::cout << "\n\n****************************************\n";
			}
		}
		else if (t == options) {
			if (optionsText != "") {
				std::cout << optionsText;
			}
		}
	}
	void DrawOptions(Player* myPlayer) {
		if (myMenu == itemMenu) {
			int itemNum = 0;
			std::list<Trinket*>::iterator item;
			AddText(textBlock::options, "OPTIONS:");
			for (int i = 0; i < myPlayer->numItems;i++) {
				Trinket* item = myPlayer->itemList[i];
				AddText(textBlock::options, ("\n" + std::to_string(itemNum) + ":    "));
				AddText(textBlock::options, (item)->title);
				itemNum++;
			}
		}
		else if (myMenu == targetMenu){
			AddText(textBlock::options, ("\n" + std::to_string(0) + ":    Target Self"));
			AddText(textBlock::options, ("\n" + std::to_string(1) + ":    Target Enemy"));
		}
		AddText(textBlock::options, "\n\n\n");
		return;
	}
	
	void SelectOption(int i, Player* myPlayer) {
		if (myMenu == itemMenu) {
			itemNum = i;
			if (myPlayer->numItems > itemNum) {
				myMenu = targetMenu;
			}
			return;
		}
		if (myMenu == targetMenu) {
			myMenu = itemMenu;
			//Character* target = new Character();
			Character* target = myPlayer;
			AddText(textBlock::events, "Player uses "+myPlayer->itemList[itemNum]->title+" on "+target->name +".");
			AddText(textBlock::events, myPlayer->useItem(i, target));
			return;
		}
	}
};