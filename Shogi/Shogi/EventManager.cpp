#include "EventManager.h"
#include "StateManager.h"


EventManager::EventManager() 
	: hasFocus(true){}
EventManager::~EventManager(){}

void EventManager::HandleEvent(sf::Event& _event){
	if (_event.type == sf::Event::KeyPressed){
		event[0] = true;
		code[0] = _event.key.code;
	}
	else if (_event.type == sf::Event::MouseButtonPressed){
		if (_event.mouseButton.button == 0){
			event[1] = true;
			vector[0] = sf::Vector2i(_event.mouseButton.x, _event.mouseButton.y);
		}
		else if (_event.mouseButton.button == 1){
			event[2] = true;
			vector[1] = sf::Vector2i(_event.mouseButton.x, _event.mouseButton.y);
		}
	}
	else if (_event.type == sf::Event::TextEntered){
		event[3] = true;
		code[1] = _event.text.unicode;
	}
	else if (_event.type == sf::Event::Closed){
		event[4] = true;
	}
}

void EventManager::Update(){
	State* state = states->getActiveState();
	if (event[0]){
		event[0] = false;
		if (code[0] == 15) 
			state->Key_P();
		else if (code[0] == 36)
			state->Key_Esc();
		else if (code[0] == 57)
			state->Space();
		else if (code[0] == 95){
			states->GetContext()->window->ToggleFullscreen();
			state->Position();
		}
	}
	if (event[1]){
		event[1] = false;
		state->Clicked(vector[0]);
	}
	if (event[2]){
		event[2] = false;
		state->RightClicked(vector[1]);
	}
	if (event[3]){
		event[3] = false;
		state->TextEntered(code[1]);
	}
	if (event[4]){
		states->GetContext()->window->Close();
	}
}

void EventManager::SetFocus(const bool& _focus){ 
	hasFocus = _focus; 
}

void EventManager::SetStateManager(StateManager* _states){
	states = _states;
}