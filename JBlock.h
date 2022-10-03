#pragma once
#include <iostream>								 
#include "Block.h"
#include <string>	

class JBlock : public Block {

public:


	void printBlock(Screen& screen);

	void removePreviousPosition(Screen& screen);

	bool checkIfCanMoveDown(const Screen& screen) const;

	bool checkIfCanMoveRight(const Screen& screen) const;

	bool checkIfCanMoveLeft(const Screen& screen) const;

	bool checkIfCanRotate(const Screen& screen) const;

};