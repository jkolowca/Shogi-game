#pragma once
#include <SFML/Graphics.hpp>

class StateManager;

/*klasa bazowa stanow - widokow - aplikacji*/
class State{
public:
	State(StateManager*);

	/*aktualizuje stan przy aktywacji*/
	virtual void Activate() = 0;

	/*ustawia elementy w oknie, 
	szczegolnie istotne przy zmianie rozmiaru okna*/
	virtual void Position() = 0;

	/*wyswietla stan w oknie*/
	virtual void Draw() = 0;

	/*metody do obslugi wydarzen*/
	virtual void Clicked(sf::Vector2i) =0;		//l.p. myszy, przyjmuje pozycje kursora 
	virtual void RightClicked(sf::Vector2i);	//p.p. myszy
	virtual void Key_Esc();
	virtual void Key_P();
	virtual void Space();
	virtual void TextEntered(sf::Uint32);		//wprowadzono tekst, przyjmuje kod wprowadzonego znaku
protected:
	StateManager * stateManager;
};