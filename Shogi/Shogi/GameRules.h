#pragma once
#include "Game.h"
#include "Stack.h"

enum stage{
	pPiece,
	pPositon
};

class GameRules{
public:
	GameRules(Game*);
	~GameRules();

	/*przetwarza klikniece, uruchamia odpowiednia metode
	w zaleznosci od aktywnego etapu ruchu*/
	void ProcessInput(sf::Vector2i);

	/*w reakcji na klikniecie pp myszy 
	sprawdza czy kliknieto na pionku ktory aktualnie moze byc promowany;
	jesli tak, promuje go*/
	void Promote(sf::Vector2i);
	/*cofa ostatni ruch*/
	void UndoMove();
	/*czysci historie ruchow*/
	void ClearHistory();
private:
	/*pierwszy etap ruchu - wybranie pionka do przesuniecia*/
	void PickPiece(sf::Vector2i);
	/*drugi etap ruchu - wybranie pola*/
	void PickPosition(sf::Vector2i);
	/*czysci informacje o aktualnym ruchu*/
	void ClearMove();
	/*sprawdza czy przesuniety pionek moze byc promowany*/
	void CheckPromotion();

	Game * game;
	stage activeStage;			//informacja o aktywnym stanie ruchu
	Piece* canBePromoted;
	Stack history;				//stos przechowujacy historie ruchow
	moveInfo move;				//przechowuje informacje o aktualnym ruchu
};