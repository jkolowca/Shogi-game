#include "Piece_Lance.h"


Piece_Lance::Piece_Lance(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\10.png");
}
Piece_Lance::~Piece_Lance(){}

bool Piece_Lance::CalculateStandardMoves(int(*_players)[9][9]){
	int direction = -1;
	if (player) direction = 1;

	bool found = false;
	ClearMoves();

	for (int i = coord.x + direction; IsOnBoard(i, coord.y); i += direction){
		if (IsSamePlayer((*_players)[i][coord.y])) break;
		moves[i][coord.y] = 1;
		found = true;
		if ((*_players)[i][coord.y] != -1) break;
	}
	return found;
}

void Piece_Lance::SetPromoted(bool _promotion){
	promoted = _promotion;
	if (_promotion) sprite.SetTexture("dep\\im\\11.png");
	else sprite.SetTexture("dep\\im\\10.png");
}