#include "Game.h"
#include "Piece_Bishop.h"
#include "Piece_GGeneral.h"
#include "Piece_King.h"
#include "Piece_Knight.h"
#include "Piece_Lance.h"
#include "Piece_Pawn.h"
#include "Piece_Rook.h"
#include "Piece_SGeneral.h"

Game::Game() 
	: player{{0},{1}}, finished(false){
	unsigned int id = 0;
	for (unsigned int i = 0; i < 2; i++){
		pieces.push_back(new Piece_Lance(id++));
		pieces.push_back(new Piece_Knight(id++));
		pieces.push_back(new Piece_SGeneral(id++));
		pieces.push_back(new Piece_GGeneral(id++));
		pieces.push_back(new Piece_King(id++));
		pieces.push_back(new Piece_GGeneral(id++));
		pieces.push_back(new Piece_SGeneral(id++));
		pieces.push_back(new Piece_Knight(id++));
		pieces.push_back(new Piece_Lance(id++));
		pieces.push_back(new Piece_Rook(id++));
		pieces.push_back(new Piece_Bishop(id++));
		for (unsigned int i = 0; i < 9; i++){
			pieces.push_back(new Piece_Pawn(id++));
		}
	}
}

Game::~Game(){
	for (std::vector<Piece*>::iterator it = pieces.begin(); it != pieces.end(); ++it){
		delete *it;
	}
	pieces.clear();
}

void Game::Position(sf::Vector2u _windowSize){
	board.Position(_windowSize);
	player[0].Position(_windowSize);
	player[1].Position(_windowSize);
}

void Game::Draw(sf::RenderWindow* _window){
	board.Draw(_window);

	player[0].Draw(_window);
	player[1].Draw(_window);

	for (unsigned int i = 0; i < 40; i++){
		pieces[i]->Draw(_window);
	}
}

Board* Game::GetBoard(){
	return &board;
}

Player* Game::GetPlayer(int _id){
	return &player[_id];
}

Player* Game::GetActivePlayer(){
	return GetPlayer(activePlayerId);
}

Square* Game::SquareSelected(sf::Vector2i _mousePos){
	return board.Clicked(_mousePos);
}

Piece* Game::PieceSelected(sf::Vector2i _mousePos){
	for (unsigned int i = 0; i < 40; i++){
		if (pieces[i]->Clicked(_mousePos)) return pieces[i];
	}
	return nullptr;
}

void Game::End(){
	finished = true;
}

void Game::Clear(){
	finished = false;
	board.Clear();
	player[0].Clear();
	player[1].Clear();
	for (unsigned int i = 0; i < 40; i++){
		pieces[i]->SetPromoted(false);
	}
}

bool Game::IsPlaying(){
	return !finished;
}

void Game::NewTurn(){
	bool t = activePlayerId;
	player[activePlayerId].Deactivate();
	activePlayerId = (int)!t;
	player[activePlayerId].Activate();
}

std::istream& operator>>(std::istream& _is, Game* & _game){
	for (unsigned int i = 0; i < 40; i++){
		_is >> _game->pieces[i];
	}
	int t;
	for (unsigned int x = 0; x < 9; x++){
		for (unsigned int y = 0; y < 9; y++){
			_is >> t;
			if (t > 39) throw(2);
			if (t > -1)
				_game->board.MovePiece(_game->pieces[t], sf::Vector2i(x, y));
		}
	}
	for (unsigned int i = 0; i < 2; i++){
		_is >> t;
		if (t > 39) throw(3);
		while (t > -1){
			_game->player[i].CapturePiece(_game->pieces[t]);
			_is >> t;
		}
	}
	_is >> _game->activePlayerId;
	if (_game->activePlayerId != 1 && _game->activePlayerId != 0) throw(4);
	_game->player[_game->activePlayerId].Activate();

	return _is;
}

std::ostream& operator<<(std::ostream& _os, Game* & _game){
	for (unsigned int i = 0; i < 40; i++){
		_os << _game->pieces[i] << std::endl;
	}
	_os << _game->board << std::endl
		<< _game->player[0] << std::endl
		<< _game->player[1] << std::endl
		<< _game->activePlayerId;
	return _os;
}