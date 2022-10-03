#pragma once
#include <iostream>								 
#include <string>	
#include "Block.h"

class IBlock : public Block {

public:


	void printBlock(Screen& screen);

	void removePreviousPosition(Screen& screen);

	bool checkIfCanMoveDown(const Screen& screen) const;

	bool checkIfCanMoveRight(const Screen& screen) const;

	bool checkIfCanMoveLeft(const Screen& screen) const;

	bool checkIfCanRotate(const Screen& screen) const;

};

