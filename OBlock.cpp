#include "OBlock.h"

void OBlock::printBlock(Screen& screen) {

	string* gamePanel = screen.getPanel();

	gamePanel[yPos][xPos] = boxSlotValue;
	gamePanel[yPos][xPos + 1] = boxSlotValue;
	gamePanel[yPos + 1][xPos] = boxSlotValue;
	gamePanel[yPos + 1][xPos + 1] = boxSlotValue;
}

void OBlock::removePreviousPosition(Screen& screen) {

	string* gameokvir = screen.getPanel();

	gameokvir[yPos][xPos] = emptySlotValue;
	gameokvir[yPos][xPos + 1] = emptySlotValue;
	gameokvir[yPos + 1][xPos] = emptySlotValue;
	gameokvir[yPos + 1][xPos + 1] = emptySlotValue;

}

bool OBlock::checkIfCanMoveDown(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (gameokvir[yPos + 1 + 1][xPos] != emptySlotValue ||
		gameokvir[yPos + 1 + 1][xPos + 1] != emptySlotValue
		)
		return false;
	else
		return true;

}

bool OBlock::checkIfCanMoveRight(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (gameokvir[yPos][xPos + 1 + 1] != emptySlotValue ||
		gameokvir[yPos + 1][xPos + 1 + 1] != emptySlotValue
		)
		return false;
	else
		return true;

}

bool OBlock::checkIfCanMoveLeft(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (xPos == 0) { return false; }

	if (gameokvir[yPos][xPos - 1] != emptySlotValue ||
		gameokvir[yPos + 1][xPos - 1] != emptySlotValue
		)
		return false;
	else
		return true;

}

bool OBlock::checkIfCanRotate(const Screen& screen) const {

	return false;

}