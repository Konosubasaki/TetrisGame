#include "Block.h"
 
Block::Block()
{

	yPos = 1;
	xPos = 6;
	rotation = 0;

}

bool Block::moveBlockDown(Screen& screen)
{
	if (!checkIfCanMoveDown(screen))
		return false;

	removePreviousPosition(screen);

	++yPos;
	return true;
}

void Block::moveBlockRight(Screen& screen)
{
	if (!checkIfCanMoveRight(screen)) return;

	removePreviousPosition(screen);

	++xPos;
}

void Block::moveBlockLeft(Screen& screen)
{
	if (!checkIfCanMoveLeft(screen)) return;

	removePreviousPosition(screen);

	--xPos;
}

void Block::rotate(Screen& screen)
{
	if (!checkIfCanRotate(screen)) { return; }

	if (rotation == 0) {

		removePreviousPosition(screen);
		rotation = 1;

	}
	else if (rotation == 1) {

		removePreviousPosition(screen);
		rotation = 0;

	}
}

 