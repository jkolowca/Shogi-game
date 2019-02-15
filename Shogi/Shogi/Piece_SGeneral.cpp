#include "Piece_SGeneral.h"


Piece_SGeneral::Piece_SGeneral(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\6.png");
}
Piece_SGeneral::~Piece_SGeneral(){}

bool Piece_SGeneral::CalculateStandardMoves(int(*_players)[9][9]){
	int direction = -1;
	if (player) direction = 1;

	bool found = false;
	ClearMoves();

	for (int i = coord.x-1; i < coord.x+2; i+=2){
		for (int j = coord.y-1; j < coord.y+2; j+=2){
			if (!IsOnBoard(i,j)) continue;
			if (IsSamePlayer((*_players)[i][j])) continue;
			moves[i][j] = 1;
			found = true;
		}
	}
	if (IsOnBoard(coord.x+direction, coord.y)){
		if (!IsSamePlayer((*_players)[coord.x+direction][coord.y])){
			moves[coord.x +direction][coord.y] = 1;
			found = true;
		}
	}
	return found;
}

void Piece_SGeneral::SetPromoted(bool _promotion){
	promoted = _promotion;
	if (_promotion) sprite.SetTexture("dep\\im\\7.png");
	else sprite.SetTexture("dep\\im\\6.png");
}