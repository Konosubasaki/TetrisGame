#pragma once
#include <iostream>									 
#include <string>	
#include <Windows.h>	
using std::string;
using std::cout;
using std::cin;
using std::endl;

 
class Screen {


public:


	Screen();

	~Screen();

	void moveToXY(int x, int y);

	void createPanel();

	void cleanPanel();

	void printPanel();

	int cleanRows();

	bool checkIfPanelFull() const;

	string* getPanel() const;

private:

	int screenHeight;
	int screenWidth;
	string* panel;

};