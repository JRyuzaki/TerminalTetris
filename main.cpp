#include "Tetromino.hpp"    
#include "Tetris.hpp"

#include <curses.h>
#include <unistd.h>	
#include <stdlib.h>
#include <time.h>
#include <thread>

#define GAME_UPDATE_TIME 100

void keyboardInput(Tetris& tetris){
	while(!tetris.isGameOver()){
		int pressedKey = getchar();
		switch(pressedKey){
			//case 'a':
			//	tetris.moveCurrentBlockHorizontal(-2);
			//	break;
			//case 'd':
			//	tetris.moveCurrentBlockHorizontal(2);
			//	break;
			//case 's':
			//	tetris.changeFallingSpeed(0.12);
			//	break;
			case 'q':
				tetris.rotateRight();
				break;
			case 'e':
				tetris.rotateLeft();
				break;
		}
	}
}

int main(){
	srand(time(NULL));

	Tetris tetris = Tetris{};

	std::thread keyboardInputThread(keyboardInput, std::ref(tetris));


	while(!tetris.isGameOver()){
		tetris.updateGame();
		usleep(GAME_UPDATE_TIME);
	}

	keyboardInputThread.join();
	endwin();
	return 0;
}      