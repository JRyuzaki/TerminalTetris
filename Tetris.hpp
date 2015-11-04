#ifndef TETRIS
#define TETRIS

#include <utility>
#include <sstream>
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

	long currentScore{0};

	int currentLevel{1};
public:
	Tetris(){
		this->currentTetromino = createNewTetromino();
		setGameFieldBorder();  
	}

	void updateGame(){
		if(this->currentTetromino.isFalling())
			updateTetromino();

		gameRenderer.drawGameField(this->gameField);

		if(this->currentTetromino.isFalling())
			gameRenderer.drawCurrentTetromino(this->currentTetromino);
		
		drawUI();
		gameRenderer.updateGameField();
	}

	void drawUI(){
		std::string scoreString;
		std::string levelString;

		std::stringstream sstream;
		sstream << this->currentScore;
		sstream >> scoreString;

		std::stringstream sstream2;
		sstream2 << this->currentLevel;
		sstream2 >> levelString;
		levelString = "Level: " + levelString;

		std::string scoreLabel = "Score: " + scoreString;
		gameRenderer.drawString(55, 1, "Use the W,A,S,D Keys");
		gameRenderer.drawString(75, 2, levelString);
		gameRenderer.drawString(75, 3, scoreLabel);
		gameRenderer.drawString(55, 0, "Terminal-Tetris: Created by Jovan Zivanovic");
	}

	const Tetromino& getCurrentTetromino() const{
		return this->currentTetromino;
	}

	void setGameFieldBorder(){
		for(int y = gameFieldHeight - 1; y >= 0; --y){
			for(int x = 0; x < gameFieldWidth; ++x){
				if(y == gameFieldHeight - 1){
					this->gameField[y][x] = 99;	
				}else{
					if(x < borderThickness || x > gameFieldWidth - borderThickness - 1){
						gameField[y][x] = 99;
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

	void moveHorizontallyBy(int xMovement);

	void incrementCurrentScore(int addition){
		this->currentScore += addition;
	}

	const long getCurrentScore() const{
		return this->currentScore;
	}

	void doubleTetrominoFallingSpeed(){
		this->currentTetromino.setFallingSpeed(10 + this->currentTetromino.getFallingSpeed());
	}

private:
	void updateTetromino();
	const bool isTetrominoActionValid(Tetromino& tetrominoAction);
	void implementIntoGameField(Tetromino& tetromino);
	void rotateTetromino();
	const Tetromino createNewTetromino();
	void checkGameFieldForFullLine();
	const bool checkLevelForIncrement() const;
	void incrementLevel();
	const bool checkForGameOver();
};
#endif 