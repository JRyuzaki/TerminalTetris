#ifndef GAME_FIELD
#define GAME_FIELD

#include <curses.h>

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

		init_pair(1, COLOR_GREEN, 0);
		init_pair(2, COLOR_GREEN, COLOR_GREEN);
	}
};
#endif 