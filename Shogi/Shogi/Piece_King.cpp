#include "Piece_King.h"


Piece_King::Piece_King(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\1.png");
}
Piece_King::~Piece_King(){}

void Piece_King::CalculateMoves(int(*_players)[9][9]){
	if (alive) CalculateStandardMoves(_players);
	else CalculateCapturedMoves(_players);
}

bool Piece_King::CalculateStandardMoves(int(*_players)[9][9]){
	bool found = false;
	ClearMoves();

	for (int i = coord.x - 1; i < coord.x + 2; i++){
		for (int j = coord.y-1; j < coord.y+2; j++){
			if (!IsOnBoard(i,j)) continue;
			if (IsSamePlayer((*_players)[i][j])) continue;
			if (i != coord.x || j != coord.y){
				moves[i][j] = 1;
				found = true;
			}
		}
	}
	return found;
}

bool Piece_King::IsKing(){
	return true;
}