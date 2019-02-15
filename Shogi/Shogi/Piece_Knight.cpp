#include "Piece_Knight.h"


Piece_Knight::Piece_Knight(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\8.png"); 
}

Piece_Knight::~Piece_Knight(){}

bool Piece_Knight::CalculateStandardMoves(int(*_players)[9][9]){
	int direction = -1;
	if (player) direction = 1;

	bool found = false;
	ClearMoves();
	
	int i = coord.x + 2 * direction;
	for(int j = coord.y -1; j<coord.y+2; j+=2){
		if (!IsOnBoard(i, j)) continue;
		if (IsSamePlayer((*_players)[i][j])) continue;
		moves[i][j] = 1;
		found = true;
	}
	return found;
}

void Piece_Knight::SetPromoted(bool _promotion){
	promoted = _promotion;
	if (_promotion) sprite.SetTexture("dep\\im\\9.png");
	else sprite.SetTexture("dep\\im\\8.png");
}