#include "Piece.h"
#include <iostream>

Piece::Piece(unsigned int _id) :id(_id), player(0), promoted(false), alive(true){}
Piece::~Piece(){}

void Piece::CalculateMoves(int(*_players)[9][9]){
	if (alive){
		if (promoted) CalculatePromotedMoves(_players);
		else CalculateStandardMoves(_players);
	}
	else CalculateCapturedMoves(_players);
}

void Piece::CalculateCapturedMoves(int(*_players)[9][9]){
	int tMoves[9][9] ={ 0 };							//potrzebna, bo tablica moves bedzie zmieniana przez metode CalculateStandardMoves

	for (unsigned int x = 0; x < 9; x++){				//zaznacza w tymczasowej tablicy pola, ktore sa puste i mozna z nich wykonac ruch
		for (unsigned int y = 0; y < 9; y++){
			if ((*_players)[x][y] == -1){
				coord = sf::Vector2i(x, y);
				if (CalculateStandardMoves(_players)){
					tMoves[x][y] = 1;
				}
			}
		}
	}

	for (unsigned int x = 0; x < 9; x++){				//przepisuje wyniki do tablicy moves
		for (unsigned int y = 0; y < 9; y++){
			moves[x][y] = tMoves[x][y];
		}
	}

}

void Piece::CalculatePromotedMoves(int(*_players)[9][9]){
	int direction = -1;
	if (player) direction = 1;
	ClearMoves();

	for (int i = coord.x; i != coord.x + 2 * direction; i += direction) {
		for (int j = coord.y -1; j < coord.y + 2; j++){

			if (!IsOnBoard(i,j)) continue;
			if (IsSamePlayer((*_players)[i][j])) continue;
			moves[i][j] = 1;
		}
	}

	moves[coord.x][coord.y] = 0;

	if (IsOnBoard(coord.x - direction, coord.y)){
		if (!IsSamePlayer((*_players)[coord.x - direction][coord.y])){
			moves[coord.x - direction][coord.y] = 1;
		}
	}
}

bool Piece::Clicked(sf::Vector2i _mousePos){
	if (_mousePos.x >= boardPosition.x - 4 * 60 + coord.y * 60 - 30.0f &&
		_mousePos.x <= boardPosition.x - 4 * 60 + coord.y * 60 + 30.0f &&
		_mousePos.y >= boardPosition.y - 4 * 60 + coord.x * 60 - 30.0f &&
		_mousePos.y <= boardPosition.y - 4 * 60 + coord.x * 60 + 30.0f)
		return true;
	else
		return false;
}

void Piece::Draw(sf::RenderWindow* _window){
	sprite.Draw(_window);
}

void Piece::Position(sf::Vector2f _boardPosition){ 
	SetPosition(_boardPosition, coord);
}

void Piece::Select(){
	sprite.SetColor(sf::Color(100, 200, 200, 255));
}

void Piece::Deselect(){
	sprite.SetColor(sf::Color(255, 255, 255, 255));
}

void Piece::SetAlive(bool _alive){
	alive = _alive;
	if (alive) return;
	SetPlayer(!(bool)player);
}

void Piece::SetPlayer(int _player){
	if (player != _player){
		player = _player;
		sprite.RotateTexture(player);
	}
}

void Piece::SetPromoted(bool _promotion){}

void Piece::SetPosition(sf::Vector2f _boardPosition, sf::Vector2i _position){
	coord = _position;
	boardPosition = _boardPosition;
	sprite.SetPosition(sf::Vector2f(boardPosition.x - 4 * 60 + coord.y * 60,
		boardPosition.y - 4 * 60 + coord.x * 60));
}

bool Piece::GetAlive(){
	return alive;
}

int Piece::GetPlayer(){
	return player;
}

bool Piece::GetPromoted(){
	return promoted;
}

sf::Vector2i Piece::GetCoordinates(){
	return coord;
}

unsigned int Piece::GetId(){
	return id;
}

void Piece::GetMoves(int (*_moves)[9][9]){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			(*_moves)[i][j] = moves[i][j];
		}
	}
}

bool Piece::IsKing(){
	return false;
} 

bool Piece::IsPawn(){
	return false;
}

std::istream& operator>>(std::istream& _is, Piece* & _piece){
	int i;
	_is >> i;
	if (i != 1 && i != 0) throw(1);
	_piece->SetPlayer(i);
	_is >> i;
	if (i != 1 && i != 0) throw(1);
	_piece->SetPromoted((bool)i);
	return _is;
}

std::ostream& operator<<(std::ostream& _os, Piece* & _piece){
	_os << _piece->player << " " << (int)_piece->promoted;
	return _os;
}

bool Piece::IsSamePlayer(int _x) {
	if (_x == player || _x == player + 2) return true;
	return false;
}

bool Piece::IsOnBoard(int _x, int _y) {
	if (_x > 8 || _x < 0 || _y>8 || _y < 0) return false;
	return true;
}

void Piece::ClearMoves() {
	for (unsigned int i = 0; i < 9; i++) {
		for (unsigned int j = 0; j < 9; j++)
			moves[i][j] = 0;
	}
}