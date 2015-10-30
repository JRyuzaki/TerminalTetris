#include "Tetromino.hpp"

Tetromino::Tetromino(const float spawnX, const float spawnY){
	this->positionX = spawnX;
	this->positionY = spawnY;
	this->rotation = 0;
}


Tetromino Tetromino::createITetromino(float spawnX, float spawnY){
	Tetromino iTetromino{spawnX, spawnY};
	iTetromino.addTetrominoPiece(0, std::make_pair(-1,0));
	iTetromino.addTetrominoPiece(1, std::make_pair(0, 0));
	iTetromino.addTetrominoPiece(2, std::make_pair(1, 0));
	iTetromino.addTetrominoPiece(3, std::make_pair(2, 0));
	return iTetromino;
}

Tetromino Tetromino::createJTetromino(float spawnX, float spawnY){
	Tetromino jTetromino{spawnX, spawnY};
	jTetromino.addTetrominoPiece(0, std::make_pair(-1, 0));
	jTetromino.addTetrominoPiece(1, std::make_pair(0, 0));
	jTetromino.addTetrominoPiece(2, std::make_pair(1, 0));
	jTetromino.addTetrominoPiece(3, std::make_pair(-1, 1));
	return jTetromino;
}

Tetromino Tetromino::createLTetromino(float spawnX, float spawnY){
	Tetromino lTetromino{spawnX, spawnY};
	lTetromino.addTetrominoPiece(0, std::make_pair(-1, 0));
	lTetromino.addTetrominoPiece(1, std::make_pair(0, 0));
	lTetromino.addTetrominoPiece(2, std::make_pair(1, 0));
	lTetromino.addTetrominoPiece(3, std::make_pair(1, 1));
	return lTetromino;
}

Tetromino Tetromino::createOTetromino(float spawnX, float spawnY){
	Tetromino oTetromino{spawnX, spawnY};
	oTetromino.addTetrominoPiece(0, std::make_pair(0, 0));
	oTetromino.addTetrominoPiece(1, std::make_pair(1, 0));
	oTetromino.addTetrominoPiece(2, std::make_pair(1, 1));
	oTetromino.addTetrominoPiece(3, std::make_pair(0, 1));
	return oTetromino;
}

Tetromino Tetromino::createSTetromino(float spawnX, float spawnY){
	Tetromino sTetromino{spawnX, spawnY};
	sTetromino.addTetrominoPiece(0, std::make_pair(0, 0));
	sTetromino.addTetrominoPiece(1, std::make_pair(-1, 0));
	sTetromino.addTetrominoPiece(2, std::make_pair(0, 1));
	sTetromino.addTetrominoPiece(3, std::make_pair(1, 1));
	return sTetromino;
}

Tetromino Tetromino::createZTetromino(float spawnX, float spawnY){
	Tetromino zTetromino{spawnX, spawnY};
	zTetromino.addTetrominoPiece(0, std::make_pair(0, 0));
	zTetromino.addTetrominoPiece(1, std::make_pair(1, 0));
	zTetromino.addTetrominoPiece(2, std::make_pair(0, 1));
	zTetromino.addTetrominoPiece(3, std::make_pair(-1, 1));
	return zTetromino;
}

Tetromino Tetromino::createTTetromino(float spawnX, float spawnY){
	Tetromino tTetromino{spawnX, spawnY};
	tTetromino.addTetrominoPiece(0, std::make_pair(0, 0));
	tTetromino.addTetrominoPiece(1, std::make_pair(-1, 0));
	tTetromino.addTetrominoPiece(2, std::make_pair(2, 0));
	tTetromino.addTetrominoPiece(3, std::make_pair(0, 1));
	return tTetromino;
}