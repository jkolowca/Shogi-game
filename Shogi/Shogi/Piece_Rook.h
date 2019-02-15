#pragma once
#include "Piece.h"

class Piece_Rook : public Piece
{
public:
	Piece_Rook(unsigned int);
	~Piece_Rook();

	bool CalculateStandardMoves(int(*)[9][9]);
	void CalculatePromotedMoves(int(*)[9][9]);

	void SetPromoted(bool);
};