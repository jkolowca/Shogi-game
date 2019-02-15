#pragma once
#include "State.h"
#include "GameRules.h"
#include "Game.h"
#include "GameLoader.h"

class State_Game : public State{
public:
	State_Game(StateManager*);

	void Activate();

	void Position();
	void Draw();

	void Clicked(sf::Vector2i);
	void RightClicked(sf::Vector2i);
	void Key_P();
private:
	Button buttons[2];
	Game game;
	GameRules rules;
	GameLoader loader;
};