#pragma once
#include <iostream>								 
#include <string>	
#include "Screen.h"


class Block {

public:


	Block();

	bool moveBlockDown(Screen& screen);

	void moveBlockRight(Screen& screen);

	void moveBlockLeft(Screen& screen);

	void rotate(Screen& screen);

	virtual void printBlock(Screen& screen) = 0;

	virtual void removePreviousPosition(Screen& screen) = 0;

	virtual bool checkIfCanMoveDown(const Screen& screen) const = 0;

	virtual bool checkIfCanMoveRight(const Screen& screen) const = 0;

	virtual bool checkIfCanMoveLeft(const Screen& screen) const = 0;

	virtual bool checkIfCanRotate(const Screen& screen) const = 0;


protected:

	int xPos;
	int yPos;
	unsigned int rotation;
	const unsigned char boxSlotValue = 176;
	const unsigned char emptySlotValue = 32;

};

