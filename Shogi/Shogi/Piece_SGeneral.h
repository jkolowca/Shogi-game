#pragma once
#include "Piece.h"

class Piece_SGeneral : public Piece
{
public:
	Piece_SGeneral(unsigned int);
	~Piece_SGeneral();

	bool CalculateStandardMoves(int(*)[9][9]);
	
	void SetPromoted(bool);
};