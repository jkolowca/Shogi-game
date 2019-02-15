#include "State_Intro.h"
#include "StateManager.h"

State_Intro::State_Intro(StateManager* _stateManager)
	: State(_stateManager), sprite("dep\\im\\i.png"){}

void State_Intro::Position(){
	sf::Vector2u windowSize = stateManager->GetContext()->window->GetRenderWindow()->getSize();
	sprite.SetPosition (sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f - 30));
}

void State_Intro::Draw(){
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();

	sprite.Draw(window);
}

void State_Intro::Space(){
	stateManager->SwitchTo(StateType::MainMenu);
}

void State_Intro::Activate(){ 
	Position(); 
}