/*
Author: Abigail Miller

Description:
Stores and prints all relevant text to screen in an orderly fashion.
*/

#pragma once
#include <string>
#include <iostream>

class Buffer {
private:
	std::string text;

public:
	void addText(std::string newText) {
		text += newText;
	}
	void clear() {
		text = "";
	}
	void print() {
		if (text != "") {
			std::cout << "\n****************************************\n";
			std::cout << text;
			std::cout << "\n\n****************************************\n";
		}
	}
};