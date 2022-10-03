#include "SBlock.h"

void SBlock::printBlock(Screen& screen) {

	string* gamePanel = screen.getPanel();

	if (rotation == 0) {

		gamePanel[yPos][xPos] = boxSlotValue;
		gamePanel[yPos + 1][xPos] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 1] = boxSlotValue;
		gamePanel[yPos + 2][xPos + 1] = boxSlotValue;
	}
	else if (rotation == 1) {

		gamePanel[yPos][xPos + 1] = boxSlotValue;
		gamePanel[yPos][xPos + 2] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 1] = boxSlotValue;
		gamePanel[yPos + 1][xPos + 0] = boxSlotValue;

	}

}

void SBlock::removePreviousPosition(Screen& screen) {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {

		gameokvir[yPos][xPos] = emptySlotValue;
		gameokvir[yPos + 1][xPos] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 1] = emptySlotValue;
		gameokvir[yPos + 2][xPos + 1] = emptySlotValue;

	}
	else if (rotation == 1) {

		gameokvir[yPos][xPos + 1] = emptySlotValue;
		gameokvir[yPos][xPos + 2] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 1] = emptySlotValue;
		gameokvir[yPos + 1][xPos + 0] = emptySlotValue;

	}
}

bool SBlock::checkIfCanMoveDown(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {

		if (gameokvir[yPos + 1 + 1][xPos] != emptySlotValue ||
			gameokvir[yPos + 2 + 1][xPos + 1] != emptySlotValue
			)
			return false;
	}
	else if (rotation == 1) {

		if (gameokvir[yPos + 1 + 1][xPos] != emptySlotValue ||
			gameokvir[yPos + 1 + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 0 + 1][xPos + 2] != emptySlotValue
			)
			return false;
	}
	return true;

}

bool SBlock::checkIfCanMoveRight(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {

		if (
			gameokvir[yPos][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1 + 1] != emptySlotValue ||
			gameokvir[yPos + 2][xPos + 1 + 1] != emptySlotValue
			)
			return false;

	}
	else if (rotation == 1) {

		if (
			gameokvir[yPos][xPos + 2 + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1 + 1] != emptySlotValue
			)
			return false;
	}

	return true;
}

bool SBlock::checkIfCanMoveLeft(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (xPos == 0) { return false; }

	if (rotation == 0) {

		if (
			gameokvir[yPos][xPos - 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos - 1] != emptySlotValue ||
			gameokvir[yPos + 2][xPos + 1 - 1] != emptySlotValue
			)
			return false;


	}
	else if (rotation == 1) {

		if (
			gameokvir[yPos][xPos + 1 - 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos - 1] != emptySlotValue
			)
			return false;

	}

	return true;
}

bool SBlock::checkIfCanRotate(const Screen& screen) const {

	string* gameokvir = screen.getPanel();

	if (rotation == 0) {
		if (
			gameokvir[yPos][xPos + 1] != emptySlotValue ||
			gameokvir[yPos][xPos + 2] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 0] != emptySlotValue
			)
			return false;

	}
	else if (rotation == 1) {
		if (
			gameokvir[yPos][xPos] != emptySlotValue ||
			gameokvir[yPos + 1][xPos] != emptySlotValue ||
			gameokvir[yPos + 1][xPos + 1] != emptySlotValue ||
			gameokvir[yPos + 2][xPos + 1] != emptySlotValue
			)
			return false;

	}

	return true;
}