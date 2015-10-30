#include "Tetromino.hpp"    
#include "Tetris.hpp"

#include <unistd.h>	
#include <stdlib.h>
#include <time.h>

#define GAME_UPDATE_TIME 100

int main(){
	srand(time(NULL));

	Tetris tetris = Tetris{};

	while(!tetris.isGameOver()){
		tetris.updateGame();
		//tetris.rotateRight();
		usleep(GAME_UPDATE_TIME);
	}

	getchar();
	endwin();
	return 0;
}      