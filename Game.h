#pragma once
#include <iostream>									 
#include <string>	
#include "Block.h"
#include "GBlock.h"
#include "IBlock.h"
#include "OBlock.h"
#include "JBlock.h"
#include "SBlock.h"
#include "TBlock.h"
#include "ZBlock.h"

class Game {


public:


	Game();

	void initialization();

	void printGameScreen(Block* blockPnt);

	void play();

	void restartGame();

	Block* createRandomBlock();

	void printGameText();

	void showMenu();

	private:

		Screen screen;
		unsigned int totalScore;
		unsigned int gameSpeed;

};