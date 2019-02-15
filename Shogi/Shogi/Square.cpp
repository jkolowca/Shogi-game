#include "Square.h"

Square::Square(){
	piece = nullptr;
	button.SetSize(sf::Vector2f(60.0f, 60.0f));
	button.SetColor(sf::Color(255, 255, 255, 0));
}
Square::~Square(){}

void Square::Draw(sf::RenderWindow* _window){
	button.Draw(_window);
}

bool Square::Clicked(sf::Vector2i _mousePos){
	return button.Clicked(_mousePos);
}

void Square::SetPosition(sf::Vector2f _position, sf::Vector2i _coordinates){
	button.SetPosition(sf::Vector2f(_position.x - 4 * 60 + _coordinates.x * 60, _position.y - 4 * 60 + _coordinates.y * 60));
	coordinates = sf::Vector2i(_coordinates.y, _coordinates.x);
}

void Square::SetPiece(Piece* _piece){
	piece = _piece;
}

void Square::RemovePiece(){
	piece = nullptr;
}

void Square::Select(){
	button.Select();
	button.SetColor(sf::Color(255, 255, 255, 50));
}

void Square::Deselect(){
	button.Deselect();
	button.SetColor(sf::Color(255, 255, 255, 0));
}

bool Square::IsSelected(){
	return button.IsSelected();
}

sf::Vector2i Square::GetCoordinates(){
	return coordinates;
}

Piece* Square::GetPiece(){
	return piece;
}