#include "Screen.h"

Screen::Screen() {

	screenHeight = 30;
	screenWidth = 15;

	panel = new string[screenHeight];
	createPanel();

}

Screen::~Screen() {

	delete[] panel;

}

void Screen::moveToXY(int x, int y) {

	HANDLE hde = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD screenCord;
	screenCord.X = x;
	screenCord.Y = y;
	SetConsoleCursorPosition(hde, screenCord);

}

void Screen::createPanel() {

	for (int i = 0; i < screenHeight; i++) {

		panel[i].resize(screenWidth);
		panel[i][0] = char(221);
		panel[i][screenWidth - 1] = char(222);

		for (int j = 1; j < screenWidth - 1; j++) {

			panel[i][j] = ' ';
		}
	}

	for (int i = 0; i < panel[0].size(); i++) {

		panel[0][i] = char(220);
		panel[screenHeight - 1][i] = char(223);
	}
}

void Screen::cleanPanel() {

	for (int i = 1; i < screenHeight - 1; i++) {

		for (int j = 1; j < screenWidth - 1; j++) {

			panel[i][j] = ' ';
		}
	}
}

void Screen::printPanel() {

	for (int i = 0; i < screenHeight; i++) {
		moveToXY(0, i);
		cout << panel[i] << endl;
	}

}

int Screen::cleanRows() {

	int rowsCleaned = 0;
	for (int i = screenHeight - 1 - 1; i > 0; i--) {

		bool rowIsFull = true;


		for (int j = 1; j < screenWidth - 1 && rowIsFull; j++) {

			if (panel[i][j] == ' ') {
				rowIsFull = false;
				break;
			}

		}
		if (rowIsFull == true) {

			int redzabrisanje = i;
			rowsCleaned++;

			for (int j = 1; j < screenWidth - 1; j++) {

				panel[redzabrisanje][j] = ' ';
			}

			for (int o = redzabrisanje - 1; o > 0; o--) {

				panel[o + 1] = panel[o];

			}
			i++;

		}

	}

	return rowsCleaned;

}

bool Screen::checkIfPanelFull() const {

	for (int i = 1; i <= 3; i++) {

		for (int j = 1; j < screenWidth - 1; j++) {

			if (panel[i][j] != ' ') return true;

		}
	}

	return false;

}

string* Screen::getPanel() const
{
	return panel;
}

