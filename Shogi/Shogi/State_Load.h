#pragma once
#include "State.h"
#include "Button.h"
#include <array>

class State_Load : public State{
public:
	State_Load(StateManager*);

	void Activate();

	void Position();
	void Draw();

	void Clicked(sf::Vector2i);

private:
	void loadFiles();
	void select(int);
	int selected;
	std::string filenames[5];
	Text title;
	Button button[2];
	Button choice[5];
};