#pragma once
#include <SFML\Graphics.hpp>
#include "Sprite.h"
#include <string>


class Piece
{
public:
	Piece(unsigned int);
	virtual ~Piece();

	/*wywoluje odpowiednia metoda obliczajaca dostepne ruchy w zaleznosci od stanu pionka*/
	void CalculateMoves(int (*)[9][9]);

	/*tylko informuje czy pionek zostal klikniety*/
	bool Clicked(sf::Vector2i);
	void Draw(sf::RenderWindow*);
	/*poprawia polozenie pionka na planszy (po zmianie rozmiaru okna)
	NIE zmienia pola na ktorym stoi pionek*/
	void Position(sf::Vector2f);

	/*podswietla pionek*/
	void Select();
	void Deselect();

	/*zmienia stan pionka, jesli pionek zostal zbity
	zmienia jego wlasciciela*/
	void SetAlive(bool);
	/*ustawia wlasciciela pionka, jesli sie zmienil 
	obraca teksture*/
	void SetPlayer(int);
	/*promuje pionka, zmiania teksture*/
	virtual void SetPromoted(bool);
	/*zmienia pozycje pionka na planszy*/
	void SetPosition(sf::Vector2f, sf::Vector2i);

	bool GetAlive();
	int GetPlayer();
	bool GetPromoted();
	sf::Vector2i GetCoordinates();
	unsigned int GetId();
	void GetMoves(int(*)[9][9]);

	/*sprawdza szczegolne przypadki pionkow*/
	virtual bool IsKing();
	virtual bool IsPawn();
	
	/*ustawia gracza pionka i ewentualnie go promuje*/
	friend std::istream& operator>>(std::istream&, Piece* &);
	friend std::ostream& operator<<(std::ostream&, Piece*&);
protected:
	/*metody obliczajace ruchy*/
	virtual bool CalculateStandardMoves(int(*)[9][9]) = 0; //zwraca informacjê, czy sa mozliwe ruchy
	/*jednakowa dla wszystkich pionkow*/
	void CalculateCapturedMoves(int(*)[9][9]);
	/*metoda uzywana dla wiekszosci pionkow ktore moga byc przesuwane,
	reszta przeladowuje te metode*/
	virtual void CalculatePromotedMoves(int(*)[9][9]);
	bool IsSamePlayer(int);
	bool IsOnBoard(int, int);
	void ClearMoves();

	Sprite sprite;
	bool alive;
	int player;
	bool promoted;
	sf::Vector2i coord;
	int moves[9][9];
private:
	sf::Vector2f boardPosition;
	unsigned int id;
};