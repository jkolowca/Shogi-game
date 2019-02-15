#pragma once
#include "Piece.h"

class Piece_King : public Piece
{
public:
	Piece_King(unsigned int);
	~Piece_King();

	void CalculateMoves(int(*)[9][9]);
	bool CalculateStandardMoves(int(*)[9][9]);

	bool IsKing();
};