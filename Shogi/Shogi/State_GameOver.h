#pragma once
#include "State.h"
#include "Button.h"

class State_GameOver : public State{
	public:
		State_GameOver(StateManager*);

		void Activate();

		void Position();
		void Draw();

		void Clicked(sf::Vector2i);
private:
	Text title;
	Button button;
};