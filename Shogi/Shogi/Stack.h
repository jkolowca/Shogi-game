#pragma once
#include "Piece.h"
#include "Square.h"

/*informacje o ruchu*/
struct moveInfo{
	Piece* movedPiece;				//pionek przesuwany
	Piece* capturedPiece;			//pionek zlapany
	Square* oldPosition;			//poprzednia pozycja pionka przesuwanego
	Square* newPosition;			//nowa pozycja pionka przesuwanego
	bool promotion;					//informacja czy pionek zostal promowany
};

/*element stosu*/
struct element{
	moveInfo info;
	element* next;
};

class Stack{
public:
	Stack();
	~Stack();
	
	/*czysci stos*/
	void Clear();
	/*zdejmuje ze stosu ostatni element*/
	moveInfo Pop();
	/*sprawdza czy stos jest pusty*/
	bool IsEmpty();

	/*towrzy nowy element z danymi informacjami 
	i dodaje go na stos*/
	Stack & operator+=(const moveInfo &);
private:
	element * head;     //element na wierzu stosu
};

