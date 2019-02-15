#pragma once
#include "State.h"
#include "Sprite.h"

class State_Intro : public State{
public:
	State_Intro(StateManager*);

	void Activate();
	void Position();
	void Draw();

	void Space();
	void Clicked(sf::Vector2i){};
private:
	Sprite sprite;
};