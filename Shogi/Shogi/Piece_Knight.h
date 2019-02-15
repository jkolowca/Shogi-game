#pragma once
#include "Piece.h"

class Piece_Knight : public Piece
{
public:
	Piece_Knight(unsigned int);
	~Piece_Knight();

	bool CalculateStandardMoves(int(*)[9][9]);

	void SetPromoted(bool);
}; 
