#pragma once
#include "Button.h"
#include "Piece.h"

/*pole tablicy*/
class Square
{
public:
	Square();
	~Square();

	void Draw(sf::RenderWindow*);
	/*informuje czy pole zostalo klikniete*/
	bool Clicked(sf::Vector2i);

	/*ustawia polozenie pionka na planszy*/
	void SetPosition(sf::Vector2f, sf::Vector2i);

	/*staiwa pionek na polu*/
	void SetPiece(Piece*);
	void RemovePiece();

	/*podswietla pole*/
	void Select();
	void Deselect();

	bool IsSelected();
	sf::Vector2i GetCoordinates();
	Piece* GetPiece();
private:
	sf::Vector2i coordinates;
	Piece* piece;
	Button button;
};