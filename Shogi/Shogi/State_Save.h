#pragma once
#include "State.h"
#include "Button.h"

class State_Save : public State{
public:
	State_Save(StateManager*);

	void Activate();

	void Position();
	void Draw();

	void Clicked(sf::Vector2i);
	void Key_Esc();
	void TextEntered(sf::Uint32);

private:
	Text title;
	Text info;
	Text entry;
	Button button;
};