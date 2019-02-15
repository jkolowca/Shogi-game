#include "Player.h"
#include <algorithm>
#define SQRSIZE 60

Player::Player(int _id) : capturedSprite("dep\\im\\c.png"), id(_id){

	std::string names[2]{
		{ "Player 1" },
		{ "Player 2" }
	};

	label.SetText(names[id]);
	label.SetSize(25);\
}
Player::~Player(){}

void Player::Draw(sf::RenderWindow* _window){
		capturedSprite.Draw(_window);
		label.Draw(_window);
}

void Player::Position(sf::Vector2u _windowSize){
	sf::Vector2f position(_windowSize.x / 2.0f, _windowSize.y / 2.0f);

	int a = 1;
	if (id) a = -a;

	label.SetPosition(sf::Vector2f(position.x + a * (7.0f*SQRSIZE + 35),
		position.y + a * SQRSIZE*4.5f));

	capturedSprite.SetPosition(sf::Vector2f(position.x + a * (7.0f*SQRSIZE + 35),
		position.y - a * SQRSIZE*1.0f));
	PositionPieces();
}

void Player::Clear(){
	captured.clear();
	Deactivate();
}

void Player::Activate(){
	label.SetColor(sf::Color(0,128,128));
}

void Player::Deactivate(){
	label.SetColor(sf::Color(255,255,255,255));
}

void Player::CapturePiece(Piece* _piece){
	captured.push_back(_piece);
	PositionPieces();
	_piece->SetAlive(false);
	_piece->SetPromoted(false);
}

void Player::PositionPieces(){

	sf::Vector2f position = capturedSprite.GetPosition();

	int i = 0;
	int j = 0;
	int r = 0;
	unsigned int size = captured.size();
	for (unsigned int it = 0; it < size; it++){
		captured[it]->SetPosition(sf::Vector2f(position.x + 3*SQRSIZE, position.y + 1*SQRSIZE), sf::Vector2i(j, i));
		i++;
		if (i == 3){
			j++;
			i = 0;
		}
	}

}

void Player::DrawPiece(Piece* _piece){

	std::vector<Piece*>::iterator it = std::find(captured.begin(), captured.end(), _piece);
	if (it != captured.end())
		captured.erase(it);
	_piece->SetAlive(true);
	PositionPieces();
}

int Player::GetId(){
	return id;
}

std::ostream& operator<<(std::ostream& _os, Player& _player){
	for (unsigned int i = 0; i < _player.captured.size(); i++){
		_os << _player.captured[i]->GetId() << " ";
	}
	_os << -1;
	return _os;
}