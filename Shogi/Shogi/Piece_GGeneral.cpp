#include "Piece_GGeneral.h"


Piece_GGeneral::Piece_GGeneral(unsigned int _id) : Piece(_id){
	sprite.SetTexture("dep\\im\\14.png"); 
}
Piece_GGeneral::~Piece_GGeneral(){}

void Piece_GGeneral::CalculateMoves(int(*_players)[9][9]){
	if (alive) CalculateStandardMoves(_players);
	else CalculateCapturedMoves(_players);
}

bool Piece_GGeneral::CalculateStandardMoves(int (*_players)[9][9]){
	int direction = -1;
	if (player) direction = 1;
	bool found = false;
	ClearMoves();
	for (int i = coord.x; i != coord.x + 2 * direction; i += direction) {
		for (int j = coord.y - 1; j < coord.y + 2; j++) {

			if (!IsOnBoard(i, j)) continue;
			if (IsSamePlayer((*_players)[i][j])) continue;
			moves[i][j] = 1;
			if (i != coord.x || j != coord.y) found = true;
		}
	}

	moves[coord.x][coord.y] = 0;

	if (IsOnBoard(coord.x - direction, coord.y)) {
		if (!IsSamePlayer((*_players)[coord.x - direction][coord.y])) {
			moves[coord.x - direction][coord.y] = 1;
			found = true;
		}
	}
	return found;
}