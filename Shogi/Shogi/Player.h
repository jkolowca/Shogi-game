#pragma once
#include "Text.h"
#include "Sprite.h"
#include "Piece.h"
#include "SharedContext.h"

class Player
{
public:
	Player(int);
	~Player();

	/*rysuje etykiete gracza i tablice z przechwyconymi pionkami,
	nie rysuje pionkow*/
	void Draw(sf::RenderWindow*);
	void Position(sf::Vector2u);
	/*wypuszcza przechwycone pionki, dezaktywuje sie*/
	void Clear();

	/*podswietla etykiete*/
	void Activate();
	void Deactivate();

	/*dodaje pionka do zlapanych*/
	void CapturePiece(Piece*);
	/*ustawia polozenie zlapanych pionkow na swojej tablicy*/
	void PositionPieces();
	/*wypuszcza pionka ze zlapanych, zmienia jego parametr na '¿ywy'*/
	void DrawPiece(Piece*);

	int GetId();

	/*wypisuje id przechwyconych pionkow*/
	friend std::ostream& operator<<(std::ostream&, Player&);
private:
	int id;
	Text label;
	Sprite capturedSprite;
	std::vector<Piece*> captured;
};