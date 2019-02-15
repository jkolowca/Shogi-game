#pragma once
#include "Sprite.h"
#include "Piece.h"
#include "SharedContext.h"

class Piece_GGeneral : public Piece
{
public:
	Piece_GGeneral(unsigned int);
	~Piece_GGeneral();

	void CalculateMoves(int(*)[9][9]);
	bool CalculateStandardMoves(int(*)[9][9]);
}; 