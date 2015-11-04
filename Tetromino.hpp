#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <utility>
#include <stdio.h>
#include <math.h>

#define CYAN 1
#define BLUE 2
#define WHITE 3
#define YELLOW 4
#define GREEN 5
#define MAGENTA 6
#define RED 7

class Tetromino{
protected:
	float positionX;
	float positionY;

	int rotation{0};
	bool rotateable{true};

	int fallingSpeed{1};
	bool fallingState{true};

	int colorID;

public:
	std::pair<int, int> tetrominoPiece[4];
	Tetromino(float spawnX, float spawnY);

	Tetromino(){
		this->positionX = 0;
		this->positionY = 0;
		this->rotation = 0;
		this->fallingState = false;
	}

	Tetromino(const Tetromino& other){
		positionX = other.getX();
		positionY = other.getY();
		rotation = other.getRotation();

		fallingState = other.isFalling();
		rotateable = other.isRotateable();

		colorID = other.getColorID();
		fallingSpeed = other.getFallingSpeed();

		for(int i = 0; i < 4; ++i){
			std::pair<int, int> otherPiece = other.getTetrominoPiece(i);
			addTetrominoPiece(i,std::make_pair(otherPiece.first, otherPiece.second));
		}
	}

	bool isFalling() const{
		return this->fallingState;
	}

	void setFallingState(const bool newFallingState){
		this->fallingState = newFallingState;
	}

	float getX() const {
		return this->positionX;
	}

	void setX(float newX){
		this->positionX = newX;
	}

	Tetromino addToX(float addition){
		Tetromino newTetromino(*this);

		newTetromino.positionX += addition;
		return newTetromino;
	}

	float getY() const{
		return this->positionY;
	}

	void setY(float newY){
		this->positionY = newY;
	}

	Tetromino addToY(float addition){
		Tetromino newTetromino(*this);

		newTetromino.positionY += addition;
		return newTetromino;
	}

	void setColorID(const int colorID){
		this->colorID = colorID;
	}

	const int getColorID() const{
		return this->colorID;
	}


	int getRotation() const {
		return this->rotation;
	}

	void addTetrominoPiece(int ID, std::pair<int, int> pieceCoordinates){
		if(ID > 3 || ID < 0)
			fprintf(stderr, "[TETROMINO.HPP/ADD_TETROMINO_PIECE]: ID INVALIDE");

		tetrominoPiece[ID] = pieceCoordinates;
	}

	std::pair<int, int> getTetrominoPiece(const int ID) const{
		return this->tetrominoPiece[ID];
	}

	const size_t getTetrominoPieceCount() const{
		return 4;
	} 

	void rotateRight(){
		if(!this->rotateable)
			return;

		++this->rotation;
		if(this->rotation > 3)
			this->rotation = 0;
	}

	void rotateLeft(){
		if(!this->rotateable)
			return;

		--this->rotation;
		if(this->rotation < 0)
			this->rotation = 3;
	}

	Tetromino applyRotation() const{
		float rotationAngle = (this->rotation * M_PI) / 2;
		Tetromino rotatedTetromino{this->positionX, this->positionY};

		for(int i = 0; i < 4; ++i){
			std::pair<int, int> originalRotation = this->tetrominoPiece[i];
			int x = originalRotation.first;
			int y = originalRotation.second;
			y *= -1;

			int newX = round(x * cos(rotationAngle) - y * sin(rotationAngle));
			int newY = round(x * sin(rotationAngle) + y * cos(rotationAngle));
			newY *= -1;

			rotatedTetromino.addTetrominoPiece(i, std::make_pair(newX, newY));
		}
		return rotatedTetromino;
	}

	const bool isRotateable() const{
		return this->rotateable;
	}

	void setRotateable(const bool rotateable){
		this->rotateable = rotateable;
	}

	const int getFallingSpeed() const{
		return this->fallingSpeed;
	}

	void setFallingSpeed(const int fallingSpeed){
		this->fallingSpeed = fallingSpeed;
	}

	static Tetromino createITetromino(float spawnX, float spawnY);
	static Tetromino createJTetromino(float spawnX, float spawnY);
	static Tetromino createLTetromino(float spawnX, float spawnY);
	static Tetromino createOTetromino(float spawnX, float spawnY);
	static Tetromino createSTetromino(float spawnX, float spawnY);
	static Tetromino createTTetromino(float spawnX, float spawnY);
	static Tetromino createZTetromino(float spawnX, float spawnY);
};
#endif 