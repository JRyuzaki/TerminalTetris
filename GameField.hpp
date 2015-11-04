#ifndef GAME_FIELD
#define GAME_FIELD

#include <curses.h>
#include <iostream>

#include "Tetromino.hpp"

class GameField{
private:
	int gameFieldWidth;
	int gameFieldHeight;

public:
	GameField(const int gameFieldWidth, const int gameFieldHeight){
		this->gameFieldWidth = gameFieldWidth;
		this->gameFieldHeight = gameFieldHeight;
		setCursesSettings();
	}

	void drawGameField(int gameField[][52]) const;
	void drawCurrentTetromino(Tetromino& tetromino) const;
	void drawString(int x, int y, std::string text){
		color_set(9, 0);
		mvaddstr(y, x, text.c_str());
	}

	void updateGameField(){
		refresh();
	}

private:
	void setCursesSettings(){
		initscr();
		noecho();
		curs_set(false);
		start_color();
		use_default_colors();

		init_pair(8, COLOR_BLACK, COLOR_BLACK);
		init_pair(9, COLOR_WHITE, COLOR_BLACK);
		init_pair(1, COLOR_CYAN, COLOR_CYAN);
		init_pair(2, COLOR_BLUE, COLOR_BLUE);
		init_pair(3, COLOR_WHITE, COLOR_WHITE);
		init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
		init_pair(5, COLOR_GREEN, COLOR_GREEN);
		init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
		init_pair(7, COLOR_RED, COLOR_RED);
	}
};
#endif 