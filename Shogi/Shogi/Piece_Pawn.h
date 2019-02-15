#pragma once
#include "Piece.h"

class Piece_Pawn: public Piece
{
public:
	Piece_Pawn(unsigned int);
	~Piece_Pawn();

	bool CalculateStandardMoves(int(*)[9][9]);

	void SetPromoted(bool);

	bool IsPawn();
};