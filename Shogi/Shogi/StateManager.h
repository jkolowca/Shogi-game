#pragma once
#include <vector>
#include <map>
#include "State.h"
#include "SharedContext.h"

/*istniejace stany gry*/
enum class StateType
{
	Intro = 0,
	MainMenu,
	Load,
	Save,
	Game, 
	Paused, 
	GameOver, 
};

/*klasa zarzadzajaca stanami gry*/
class StateManager{
public:
	StateManager(SharedContext* );
	~StateManager();

	void Draw();

	SharedContext* GetContext();
	/*zwraca wskaznik na aktywny stan aplikacji*/
	State* getActiveState();

	/*zmienia stan na wybrany*/
	void SwitchTo(StateType);
private:
	StateType activeState;
	SharedContext* shared;
	std::vector<State*> states;
};