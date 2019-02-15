#pragma once
#include "Piece.h"

class Piece_Lance : public Piece
{
public:
	Piece_Lance(unsigned int);
	~Piece_Lance();

	bool CalculateStandardMoves(int(*)[9][9]);

	void SetPromoted(bool);
};