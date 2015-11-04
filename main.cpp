#include "Tetromino.hpp"    
#include "Tetris.hpp"

#include <curses.h>
#include <unistd.h>	
#include <stdlib.h>
#include <time.h>
#include <thread>

#define GAME_UPDATE_TIME 100

void keyboardInput(Tetris&);
void drawGameOverScreen(void);

int main(){
	srand(time(NULL));

	Tetris tetris = Tetris{};

	std::thread keyboardInputThread(keyboardInput, std::ref(tetris));


	while(!tetris.isGameOver()){
		tetris.updateGame();
		usleep(GAME_UPDATE_TIME);
	}

	drawGameOverScreen();
	keyboardInputThread.join();

	getchar();
	endwin();
	return 0;
}      


void keyboardInput(Tetris& tetris){
	while(!tetris.isGameOver()){
		int pressedKey = getchar();
		switch(pressedKey){
			case 'a':
				tetris.moveHorizontallyBy(-2);
				break;
			case 'd':
				tetris.moveHorizontallyBy(2);
				break;
			case 's':
				tetris.doubleTetrominoFallingSpeed();
				break;
			case 'q':
				tetris.rotateRight();
				break;
			case 'e':
				tetris.rotateLeft();
				break;
		}
	}
}

void drawGameOverScreen(){
	erase();
	mvaddstr(0, 0, "GAME OVER");
	refresh();
}