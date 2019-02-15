#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class StateManager;

class EventManager{
public:
	EventManager();
	~EventManager();

	/*sprawdza jakie wydarzenie zostalo wprowadzone,
	oznacza to w tablicy event, 
	wpisuje odpowiednie dane do tablic code i vector*/
	void HandleEvent(sf::Event&);
	/*reaguje na wprowadzone wydarzenia*/
	void Update();


	void SetFocus(const bool&);
	void SetStateManager(StateManager*);
private:
	bool event[5];
	sf::Uint32 code[2];
	sf::Vector2i vector[2];

	bool hasFocus;				//informuje czy okno jest aktywne
	StateManager* states;
};