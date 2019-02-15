#include "Piece_Bishop.h"


Piece_Bishop::Piece_Bishop(unsigned int _id): Piece(_id){
	sprite.SetTexture("dep\\im\\4.png");
}
Piece_Bishop::~Piece_Bishop(){}

bool Piece_Bishop::CalculateStandardMoves(int(*_players)[9][9]){
	bool found = false;
	ClearMoves();

	for(int direction=1; direction >-2; direction -=2){
		int i, j;
		for (i = coord.x + direction, j = coord.y + direction; IsOnBoard(i,j); i += direction, j += direction){
			if (IsSamePlayer((*_players)[i][j])) break;
			moves[i][j] = 1;
			found = true;
			if ((*_players)[i][j] != -1) break;
		}
		for (i = coord.x + direction, j = coord.y - direction; IsOnBoard(i,j); i += direction, j -= direction){
			if (IsSamePlayer((*_players)[i][j])) break;
			moves[i][j] = 1;
			found = true;
			if ((*_players)[i][j] != -1) break;
		}
	}
	return found;
}

void Piece_Bishop::CalculatePromotedMoves(int(*_players)[9][9]) {
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

void Piece_Bishop::SetPromoted(bool _promotion){
	promoted = _promotion;
	if (_promotion) sprite.SetTexture("dep\\im\\5.png");
	else sprite.SetTexture("dep\\im\\4.png");
}