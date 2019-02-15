#include "Piece_Pawn.h"
#include <iostream>


Piece_Pawn::Piece_Pawn(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\12.png");
}
Piece_Pawn::~Piece_Pawn(){}

bool Piece_Pawn::CalculateStandardMoves(int (*_players)[9][9]){
		int direction = -1;
		if (player) direction = 1;

		bool found = false;
		ClearMoves();

		if (IsOnBoard(coord.x+direction, coord.y)){
			if (!IsSamePlayer((*_players)[coord.x+direction][coord.y])){
				moves[coord.x + direction][coord.y] = 1;
				found = true;
			}
		}
		for (unsigned int x = 0; x < 9; x++){
			if ((*_players)[x][coord.y] == player + 2) found = false;
		}
		return found;
}

bool Piece_Pawn::IsPawn(){
	if (promoted) return false;
	return true;
}

void Piece_Pawn::SetPromoted(bool _promotion){
	promoted = _promotion;
	if (_promotion) sprite.SetTexture("dep\\im\\13.png");
	else sprite.SetTexture("dep\\im\\12.png");
}