#pragma once
#include "State.h"
#include "Text.h"

class State_Paused : public State{
public:
	State_Paused(StateManager*);

	void Activate();

	void Position();
	void Draw();

	void Key_P();
	void Clicked(sf::Vector2i);
private:
	Text title;
};