#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <utility>
#include <stdio.h>
#include <curses.h>

class Tetromino{
protected:
	std::pair<int, int> tetrominoPiece[4];


public:
	void addTetrominoPiece(int ID, std::pair<int, int> pieceCoordinates){
		if(ID > 3 || ID < 0)
			fprintf(stderr, "[TETROMINO.HPP/ADD_TETROMINO_PIECE]: ID INVALIDE");

		tetrominoPiece[ID] = pieceCoordinates;
	}
};
#endif 