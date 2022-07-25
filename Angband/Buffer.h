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
		std::cout << text;
	}
};