#include "ZBlock.h"

void ZBlock::printBlock(Screen& screen) {

	string* gamePanel = screen.getPanel();

	if (rotation == 0) {

		gamePanel[yPos][xPos + 1] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 1] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 0] = boxSlotValue;
		gamePanel[yPos + 2][xPos + 0] = boxSlotValue;

	}
	else if (rotation == 1) {

		gamePanel[yPos][xPos] = boxSlotValue;
		gamePanel[yPos][xPos + 1] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 1] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 2] = boxSlotValue;

	}

}

void ZBlock::removePreviousPosition(Screen& screen) {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {

		gameokvir[yPos][xPos + 1] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 1] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 0] = emptySlotValue;
		gameokvir[yPos + 2][xPos + 0] = emptySlotValue;

	}
	else if (rotation == 1) {

		gameokvir[yPos][xPos] = emptySlotValue;
		gameokvir[yPos][xPos + 1] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 1] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 2] = emptySlotValue;

	}

}

bool ZBlock::checkIfCanMoveDown(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {

		if (gameokvir[yPos + 1 + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 2 + 1][xPos] != emptySlotValue
			)
			return false;

	}
	else if (rotation == 1) {

		if (gameokvir[yPos + 0 + 1][xPos] != emptySlotValue ||
			gameokvir[yPos + 1 + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1 + 1][xPos + 2] != emptySlotValue
			)
			return false;
	}

	return true;

}

bool ZBlock::checkIfCanMoveRight(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {

		if (gameokvir[yPos][xPos + 1 + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1 + 1] != emptySlotValue ||
			gameokvir[yPos + 2][xPos + 0 + 1] != emptySlotValue
			)
			return false;

	}
	else if (rotation == 1) {

		if (gameokvir[yPos][xPos + 1 + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 2 + 1] != emptySlotValue
			)
			return false;
	}
	return true;

}

bool ZBlock::checkIfCanMoveLeft(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (xPos == 0) { return false; }

	if (rotation == 0) {

		if (
			gameokvir[yPos][xPos + 1 - 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos - 1] != emptySlotValue ||
			gameokvir[yPos + 2][xPos - 1] != emptySlotValue
			)
			return false;

	}
	else if (rotation == 1) {

		if (
			gameokvir[yPos][xPos - 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1 - 1] != emptySlotValue
			)
			return false;

	}
	return true;

}

bool ZBlock::checkIfCanRotate(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {
		if (
			gameokvir[yPos][xPos] != emptySlotValue ||
			gameokvir[yPos][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 2] != emptySlotValue
			)
			return false;

	}
	else if (rotation == 1) {
		if (
			gameokvir[yPos][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 0] != emptySlotValue ||
			gameokvir[yPos + 2][xPos + 0] != emptySlotValue
			)
			return false;

	}

	return true;
}