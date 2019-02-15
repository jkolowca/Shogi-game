#include "Piece_Rook.h"


Piece_Rook::Piece_Rook(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\2.png"); 
}
Piece_Rook::~Piece_Rook(){}

bool Piece_Rook::CalculateStandardMoves(int(*_players)[9][9]){
	bool found = false;
	ClearMoves();

	for(int direction =-1; direction <2; direction +=2){
		for (int i = coord.x + direction; IsOnBoard(i, coord.y); i += direction){
			if (IsSamePlayer((*_players)[i][coord.y])) break;
			moves[i][coord.y] = 1;
			found = true;
			if ((*_players)[i][coord.y] != -1) break;
		}
		for (int j = coord.y + direction; IsOnBoard(coord.x, j); j += direction){
			if (IsSamePlayer((*_players)[coord.x][j])) break;
			moves[coord.x][j] = 1;
			found = true;
			if ((*_players)[coord.x][j] != -1) break;
		}
	}
	return found;
}

void Piece_Rook::CalculatePromotedMoves(int(*_players)[9][9]) {
	CalculateStandardMoves(_players);
	for (int i = coord.x - 1; i < coord.x + 2; i++) {
		for (int j = coord.y - 1; j < coord.y + 2; j++) {
			if (!IsOnBoard(i, j)) continue;
			if (IsSamePlayer((*_players)[i][j])) continue;
			moves[i][j] = 1;
		}
	}
	moves[coord.x][coord.y] = 0;
}

void Piece_Rook::SetPromoted(bool _promotion){
	promoted = _promotion;
	if (_promotion) sprite.SetTexture("dep\\im\\3.png");
	else sprite.SetTexture("dep\\im\\2.png");
}