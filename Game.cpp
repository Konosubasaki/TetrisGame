#include "Game.h"

Game::Game() {

	gameSpeed = 0;
	totalScore = 0;
}

void Game::initialization() {

	showMenu();
	play();

	screen.moveToXY(27, 20);
	cout << "GAME OVER!" << endl;
	Sleep(3000);
	restartGame();

}

void Game::printGameScreen(Block* blockPnt) {
	blockPnt->printBlock(screen);
	screen.printPanel();

}

void Game::play() {

	Block* blockPnt = nullptr;
	bool isGameOver = false;

	while (!isGameOver) {


		printGameText();

		blockPnt = createRandomBlock();

		while (blockPnt->moveBlockDown(screen)) {


			if (GetAsyncKeyState(VK_RIGHT)) {

				blockPnt->moveBlockRight(screen);

			}
			else if (GetAsyncKeyState(VK_LEFT)) {

				blockPnt->moveBlockLeft(screen);

			}
			else if (GetAsyncKeyState(VK_UP)) {
				blockPnt->rotate(screen);
			}

			printGameScreen(blockPnt);

			if (GetAsyncKeyState(VK_DOWN)) {
				Sleep(20);
			}
			else
				Sleep(gameSpeed);

		}

		totalScore += (100 * screen.cleanRows());
		isGameOver = screen.checkIfPanelFull();

		delete blockPnt;
		blockPnt = nullptr;

	}

}

void Game::restartGame() {

	totalScore = 0;
	screen.cleanPanel();
	system("CLS");
	initialization();

}

Block* Game::createRandomBlock() {

	int randomPiece = rand() % 7;

	if (randomPiece == 0) {
		return new IBlock;
	}
	else if (randomPiece == 1) {
		return new OBlock;
	}
	else if (randomPiece == 2) {
		return new JBlock;
	}
	else if (randomPiece == 3) {
		return new GBlock;
	}
	else if (randomPiece == 4) {
		return new SBlock;
	}
	else if (randomPiece == 5) {
		return new TBlock;
	}
	else {
		return new ZBlock;
	}

}

void Game::printGameText() {

	screen.moveToXY(26, 3);
	cout << "TETRIS GAME" << endl;
	screen.moveToXY(25, 6);
	cout << "Total score: " << totalScore << endl;

}

void Game::showMenu() {

	cout << "#######################################################################################" << endl;
	cout << "#                                                                                     #" << endl;
	cout << "#                                   Welcome to Tetris !                               #" << endl;
	cout << "#                                                                                     #" << endl;
	cout << "#        Use left or right arrow key on keyboard to move a block left or right.       #" << endl;
	cout << "# Use up arrow key to rotate the block. Hold down arrow key to move the block faster. #" << endl;
	cout << "#                                                                                     #" << endl;
	cout << "#                                      Good luck!                                     #" << endl;
	cout << "#                                                                                     #" << endl;
	cout << "#                                                                                     #" << endl;
	cout << "#                  Choose level: 1 for easy, 2 for medium, 3 for hard                 #" << endl;
	cout << "#                                                                                     #" << endl;
	cout << "#######################################################################################" << endl;

	int levelChoice = 0;
	cin >> levelChoice;

	if (levelChoice == 1)
		gameSpeed = 350;
	else if (levelChoice == 2)
		gameSpeed = 250;
	else if (levelChoice == 3)
		gameSpeed = 150;
	else
		gameSpeed = 250;

	system("CLS");

}