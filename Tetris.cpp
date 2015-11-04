 #include "Tetris.hpp"

void Tetris::updateTetromino(){
	if(this->currentTetromino.isFalling()){
		double fallSpeed = this->currentTetromino.getFallingSpeed();
		Tetromino updatedTetromino = this->currentTetromino.addToY(fallSpeed / 1000);
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
			newTetromino = Tetromino::createITetromino(gameFieldWidth / 2 + 2, 0);
			break;
		case 1:
			newTetromino = Tetromino::createJTetromino(gameFieldWidth / 2, 0);
			break;
		case 2:
			newTetromino = Tetromino::createLTetromino(gameFieldWidth / 2, 0);
			break;
		case 3:
			newTetromino = Tetromino::createOTetromino(gameFieldWidth / 2, 0);
			break;
		case 4:
			newTetromino = Tetromino::createSTetromino(gameFieldWidth / 2, 0);
			break;
		case 5:
			newTetromino = Tetromino::createTTetromino(gameFieldWidth / 2, 0);
			break;
		case 6:
			newTetromino = Tetromino::createZTetromino(gameFieldWidth / 2, 0);
			break;
	}

	newTetromino.setFallingSpeed(this->tetrominoFallingSpeed);
	return newTetromino;
}

const bool Tetris::isTetrominoActionValid(Tetromino& tetrominoAction){
	for(int i = 0; i < 4; ++i){
		std::pair<int, int> piece = tetrominoAction.tetrominoPiece[i];
		int x = tetrominoAction.getX() + piece.first * 2;//2 = width
		int y = piece.second + tetrominoAction.getY();

		if(this->gameField[y][x] != 0)
			return false;
	}
	return true;
}

void Tetris::implementIntoGameField(Tetromino& tetromino){
	for(int i = 0; i < 4; ++i){
		std::pair<int, int> piece = tetromino.getTetrominoPiece(i);
		int x = tetromino.getX() + piece.first * 2;
		int y = piece.second + tetromino.getY();

		for(int yOffset = 0; yOffset < 1; ++yOffset){
			for(int xOffset = 0; xOffset < 2; ++xOffset){
				this->gameField[y + yOffset][x + xOffset] = tetromino.getColorID();
			}
		}
	}

	checkGameFieldForFullLine();
	checkForGameOver();
}

void Tetris::rotateTetromino(){
	Tetromino rotatedTetromino = this->currentTetromino.applyRotation();
	if(isTetrominoActionValid(rotatedTetromino))
		this->currentTetromino = rotatedTetromino;
}

void Tetris::moveHorizontallyBy(int xMovement){
	int newX = this->currentTetromino.getX() + xMovement;
	Tetromino newTetromino = Tetromino(this->currentTetromino);
	newTetromino.setX(newX);
	if(isTetrominoActionValid(newTetromino)){
		this->currentTetromino = newTetromino;
	}
}

void Tetris::checkGameFieldForFullLine(){
	for(int y = 0; y < gameFieldHeight - 1; ++y){
		bool fullLine = true;
		for(int x = borderThickness; x < gameFieldWidth - borderThickness; ++x){
			if(this->gameField[y][x] == 0){
				fullLine = false;
				break;
			}
		}
		if(fullLine){
			incrementCurrentScore(10 * this->tetrominoFallingSpeed);

			if(checkLevelForIncrement())
				incrementLevel();

			for(int y2 = y; y2 > 0; --y2){
				for(int x = borderThickness; x < gameFieldWidth - borderThickness; ++x){
					this->gameField[y2][x] = this->gameField[y2 - 1][x];
				}
			}
		}
	}
}

const bool Tetris::checkLevelForIncrement() const{
	if((this->currentScore / 100) >= this->currentLevel)
		return true;
	return false;
}

void Tetris::incrementLevel(){
	++this->currentLevel;
	this->tetrominoFallingSpeed += 0.2;
}

const bool Tetris::checkForGameOver(){
	for(int x = gameFieldWidth / 2 - 4; x < gameFieldWidth / 2 + 4; ++x){
		if(this->gameField[0][x] != 0){
			this->gameIsOver = true;
		}
	}
}