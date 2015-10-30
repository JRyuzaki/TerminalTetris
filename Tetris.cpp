 #include "Tetris.hpp"

void Tetris::updateTetromino(){
	if(this->currentTetromino.isFalling()){
		Tetromino updatedTetromino = this->currentTetromino.addToY(this->tetrominoFallingSpeed / 1000);
		if(isTetrominoActionValid(updatedTetromino)){
			this->currentTetromino = updatedTetromino;
		}else{
			this->currentTetromino.setFallingState(false);
			implementIntoGameField(currentTetromino);
			Tetromino newTetromino = createNewTetromino();
			this->currentTetromino = newTetromino;
		}
	}
}

const Tetromino Tetris::createNewTetromino(){
	Tetromino newTetromino;
	int newTetrominoID = rand() % 7;
	switch(newTetrominoID){
		case 0: 
			newTetromino = Tetromino::createITetromino(10, 10);
			break;
		case 1:
			newTetromino = Tetromino::createJTetromino(10, 10);
			break;
		case 2:
			newTetromino = Tetromino::createLTetromino(10, 10);
			break;
		case 3:
			newTetromino = Tetromino::createOTetromino(10, 10);
			break;
		case 4:
			newTetromino = Tetromino::createSTetromino(10, 10);
			break;
		case 5:
			newTetromino = Tetromino::createTTetromino(10, 10);
			break;
		case 6:
			newTetromino = Tetromino::createZTetromino(10, 10);
			break;
	}

	return newTetromino;
}

const bool Tetris::isTetrominoActionValid(Tetromino& tetrominoAction){
	for(int i = 0; i < 4; ++i){
		std::pair<int, int> piece = tetrominoAction.tetrominoPiece[i];
		int x = tetrominoAction.getX() + (piece.first % 2) * 2;//2 = width
		int y = piece.second + tetrominoAction.getY();

		if(this->gameField[y][x] == 1)
			return false;
	}
	return true;
}

void Tetris::implementIntoGameField(Tetromino& tetromino){
	for(int i = 0; i < 4; ++i){
		std::pair<int, int> piece = tetromino.getTetrominoPiece(i);
		int x = tetromino.getX() + (piece.first % 2) * 2;//2 = width
		int y = piece.second + tetromino.getY();

		for(int yOffset = 0; yOffset < 1; ++yOffset){
			for(int xOffset = 0; xOffset < 2; ++xOffset){
				this->gameField[y + yOffset][x + xOffset] = 1;
			}
		}
	}
}

void Tetris::rotateTetromino(){
	Tetromino rotatedTetromino = this->currentTetromino.applyRotation();
	if(isTetrominoActionValid(rotatedTetromino))
		this->currentTetromino = rotatedTetromino;
}