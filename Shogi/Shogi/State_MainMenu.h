#pragma once
#include "State.h"
#include "Button.h"

class State_MainMenu : public State{
public:
	State_MainMenu(StateManager*);

	void Activate();

	void Position();
	void Draw();

	void Clicked(sf::Vector2i);
	void Key_Esc();
private:
	Text title;
	Button buttons[3];
};