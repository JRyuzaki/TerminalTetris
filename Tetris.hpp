#ifndef TETRIS
#define TETRIS

#include <utility>
#include <stdlib.h>

#include "Tetromino.hpp"
#include "GameField.hpp"

class Tetris{
private:
	static constexpr int borderThickness = 2;
	static constexpr int gameFieldWidth = 48 + borderThickness * 2;
	static constexpr int gameFieldHeight = 48;


	Tetromino currentTetromino = Tetromino{13, 7};
	float tetrominoFallingSpeed = 1;

	int gameField[gameFieldHeight][gameFieldWidth];
	GameField gameRenderer{gameFieldWidth, gameFieldHeight};

	bool gameIsOver = false;

public:
	Tetris(){
		this->currentTetromino = Tetromino::createITetromino(10, 10);
		setGameFieldBorder();  
	}

	void updateGame(){
		if(this->currentTetromino.isFalling())
			updateTetromino();

		gameRenderer.drawGameField(this->gameField);

		if(this->currentTetromino.isFalling())
			gameRenderer.drawCurrentTetromino(this->currentTetromino);
			
		gameRenderer.updateGameField();
	}

	const Tetromino& getCurrentTetromino() const{
		return this->currentTetromino;
	}

	void setGameFieldBorder(){
		for(int y = gameFieldHeight - 1; y >= 0; --y){
			for(int x = 0; x < gameFieldWidth; ++x){
				if(y == gameFieldHeight - 1){
					this->gameField[y][x] = 1;	
				}else{
					if(x < borderThickness || x > gameFieldWidth - borderThickness - 1){
						gameField[y][x] = 1;
					}
					else{
						gameField[y][x] = 0;
					}
				}
			}
		}
	}

	const bool isGameOver() const{
		return this->gameIsOver;
	}

	void setGameIsOver(const bool gameIsOver){
		this->gameIsOver = gameIsOver;
	}

	void rotateRight(){
		this->currentTetromino.rotateRight();
		rotateTetromino();
	}

	void rotateLeft(){
		this->currentTetromino.rotateLeft();
		rotateTetromino();
	}


private:
	void updateTetromino();
	const bool isTetrominoActionValid(Tetromino& tetrominoAction);
	void implementIntoGameField(Tetromino& tetromino);
	void rotateTetromino();
	const Tetromino createNewTetromino();
};
#endif 