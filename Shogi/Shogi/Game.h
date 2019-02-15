#pragma once
#include "Board.h"
#include "Player.h"
#include "SharedContext.h"
#include "Piece.h"

class Game   
{
public:
	Game();
	~Game();

	void Position(sf::Vector2u);
	void Draw(sf::RenderWindow*);

	Board* GetBoard();
	Player* GetPlayer(int);
	Player* GetActivePlayer();
	Square* SquareSelected(sf::Vector2i);
	Piece* PieceSelected(sf::Vector2i);

	/*jedynie ustawia wartosc finished na true*/
	void End();
	/*wywoluje funkcje czyszczace odpowiednie czesci gry*/
	void Clear();

	bool IsPlaying();
	/*zmienia aktywnego gracza, deaktywuje poprzedniego i aktywuje nowego*/
	void NewTurn();

	friend std::istream& operator>>(std::istream&, Game * &);
	friend std::ostream& operator<<(std::ostream&, Game* &);
private:
	bool finished;
	Board board;
	int activePlayerId;
	Player player[2];
	std::vector<Piece*> pieces;
};