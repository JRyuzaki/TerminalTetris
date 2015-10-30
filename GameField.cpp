#include "GameField.hpp"

void GameField::drawGameField(int gameField[][52]) const{
	erase();

	for(int y = 0; y < gameFieldHeight; ++y){
		for(int x = 0; x < gameFieldWidth; ++x){
			char currentFieldContent = gameField[y][x];
 
			if(currentFieldContent != 0){
				color_set(currentFieldContent, 0);
				mvaddstr(y, x, " ");
			}
		}
	} 
}   

void GameField::drawCurrentTetromino(Tetromino& tetromino) const{
	for(int i = 0; i < tetromino.getTetrominoPieceCount() ; ++i){
		std::pair<int, int> tetrominoPiece = tetromino.getTetrominoPiece(i);
		
		int x = (tetrominoPiece.first);

		if(x < 0){
			int absX = x * -1;
			if(absX % 2 == 1)
				--x;
		}else{
			if(x % 2 == 1)
				++x;
		}
		x += tetromino.getX();
		

		int y = tetromino.getY() + tetrominoPiece.second;


		color_set(2, 0);
		for(int height = 0; height < 1; ++height){
			for(int width = 0; width < 2; ++width){
				mvaddstr(y + height, x + width, " ");
			}
		}
	}
}