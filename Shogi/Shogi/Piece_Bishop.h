#pragma once
#include "Sprite.h"
#include "Piece.h"
#include "SharedContext.h"

class Piece_Bishop : public Piece
{
public:
	Piece_Bishop(unsigned int);
	~Piece_Bishop();

	bool CalculateStandardMoves(int(*)[9][9]);
	void CalculatePromotedMoves(int(*)[9][9]);

	void SetPromoted(bool);
};