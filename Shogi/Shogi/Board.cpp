#include "Board.h"


Board::Board() 
	: boardSprite("dep\\im\\b.png"){}
Board::~Board(){}

void Board::Draw(sf::RenderWindow* _window){
	boardSprite.Draw(_window);
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			board[i][j].Draw(_window);
		}
	}
}

void Board::Position(sf::Vector2u _windowSize){
	sf::Vector2f position (_windowSize.x / 2.0f, _windowSize.y / 2.0f);
	boardSprite.SetPosition(position);
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			board[i][j].SetPosition(position, sf::Vector2i(j,i));
			if (board[i][j].GetPiece())board[i][j].GetPiece()->SetPosition(position, sf::Vector2i(i, j));
		}
	}
}

void Board::Clear(){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			board[i][j].SetPiece(nullptr);
		}
	}
}


Square* Board::Clicked(sf::Vector2i _mousePos){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			if (board[i][j].Clicked(_mousePos)){
				return &board[i][j];
			}
		}
	}
	return nullptr;
}

sf::Vector2f Board::GetPosition(){
	return boardSprite.GetPosition();
}

void Board::HighlightMoves(Piece* _piece){
	int moves[9][9];
	GetPlayersPositions(&moves);
	_piece->CalculateMoves(&moves);
	_piece->GetMoves(&moves);
	SelectSquares(&moves);
}

void Board::Deselect(){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			board[i][j].Deselect();
		}
	}
}

int Board::GetPieceAt(sf::Vector2i _coordinates){
	if(!board[_coordinates.x][_coordinates.y].GetPiece()) return -1;
	else return board[_coordinates.x][_coordinates.y].GetPiece()->GetId();
}

void Board::MovePiece(Piece* _piece, sf::Vector2i _coordinates){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			if (board[i][j].GetPiece()){
				if (board[i][j].GetPiece() == _piece)
					board[i][j].SetPiece(nullptr);
			}
		}
	}
	board[_coordinates.x][_coordinates.y].SetPiece(_piece);
	_piece->SetPosition(GetPosition(), _coordinates);
}

std::ostream& operator<<(std::ostream& _os, Board& _board){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			if(Piece* piece = _board.board[i][j].GetPiece())
			_os << piece->GetId() << " ";
			else _os << -1 << " ";
		}
		_os << std::endl;
	}
	return _os;
}

void Board::SelectSquares(int(*_squares)[9][9]){
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			if ((*_squares)[i][j])
				board[i][j].Select();
		}
	}
}

void Board::GetPlayersPositions(int (*_positions)[9][9]){
	Piece* temp;
	for (unsigned int i = 0; i < 9; i++){
		for (unsigned int j = 0; j < 9; j++){
			temp = board[i][j].GetPiece();
			if (temp==nullptr) (*_positions)[i][j] = -1;								//puste pole - wartosc -1
			else if (temp->IsPawn()) (*_positions)[i][j] = (temp->GetPlayer() + 2);		//pozostalym pionkom nadaje wartosci zaleznie od gracza
			else (*_positions)[i][j] = temp->GetPlayer();								//pionki typu pawn dostaja wlasna wartosc, bo moze byc tylko jeden w kolumnie
		}
	}
}