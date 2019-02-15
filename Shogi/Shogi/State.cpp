#include "State.h"
#include "StateManager.h"

State::State(StateManager* _stateManager)
	: stateManager(_stateManager){}

void State::RightClicked(sf::Vector2i){}
void State::Key_Esc(){
	stateManager->SwitchTo(StateType::MainMenu);
}
void State::Key_P(){}
void State::Space(){}
void State::TextEntered(sf::Uint32){}