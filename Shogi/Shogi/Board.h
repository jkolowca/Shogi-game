#pragma once
#include "SharedContext.h"
#include "Square.h"
#include "Sprite.h"
#include "Piece.h"

/*tablica na ktorej stoja pionki*/
class Board
{
public:
	Board();
	~Board();


	void Draw(sf::RenderWindow*);
	void Position(sf::Vector2u);
	/*usuwa pionki z tablicy*/
	void Clear();
	
	/*zwraca wskaünik na klikniete pole tablicy,
	przyjmuje wspolrzedne kursora myszy*/
	Square* Clicked(sf::Vector2i);

	/*zwraca pozycje srodka obrazu tablicy w oknie*/
	sf::Vector2f GetPosition();

	/*podswietla pola na ktorych moze stanac wybrany pionek*/
	void HighlightMoves(Piece*);
	void Deselect();

	/*zwraca indeks pionka na wskazanym polu tablicy,
	jesli go nie ma zwraca -1*/
	int GetPieceAt(sf::Vector2i);

	/*sprawdza czy dany pionek jest juz na tablicy,
	usuwa go przy znalezieniu i ustawia na nowym polu*/
	void MovePiece(Piece*, sf::Vector2i);

	/*wypisuje wierszami indeksy pionkow na tablicy,
	jesli pole jest puste wypisuje -1*/
	friend std::ostream& operator<<(std::ostream&, Board&);
private:
	void SelectSquares(int(*)[9][9]);			//podswietla pola wskazane w tablicy
	void GetPlayersPositions(int(*)[9][9]);		//wpsiuje do tablicy informacje na podstawie ktorej pionki ustalaja mozliwe ruchy
	Sprite boardSprite;
	Square board[9][9];							//tablica, board[0][0] odpowiada lewemu gornemu polu na tablicy
};