#include "GameField.hpp"

void GameField::drawGameField(int gameField[][52]) const{
	erase();

	for(int y = 0; y < gameFieldHeight; ++y){
		for(int x = 0; x < gameFieldWidth; ++x){
			char currentFieldContent = gameField[y][x];
 		
 			if(currentFieldContent != 0){
				if(currentFieldContent != 99){
					color_set(currentFieldContent, 0);
				}else{
					color_set(8, 0);
				}
				mvaddstr(y, x, " ");
			}
		}
	} 
}   

void GameField::drawCurrentTetromino(Tetromino& tetromino) const{
	for(int i = 0; i < tetromino.getTetrominoPieceCount() ; ++i){
		std::pair<int, int> tetrominoPiece = tetromino.getTetrominoPiece(i);
		int x = tetromino.getX() + 2 * tetrominoPiece.first;	//TODO: CONNECT TO TETRIS.HPP FOR THE THICKNESS 
		int y = tetromino.getY() + 1 * tetrominoPiece.second;


		color_set(tetromino.getColorID(), 0);
		for(int height = 0; height < 1; ++height){
			for(int width = 0; width < 2; ++width){
				mvaddstr(y + height, x + width, " ");
			}
		}
	}
}