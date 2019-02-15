#include "State_Paused.h"
#include "StateManager.h"

State_Paused::State_Paused(StateManager* _stateManager): State(_stateManager){
	title.SetText("PAUSED");
	title.SetSize(30);
}

void State_Paused::Activate(){ 
	Position(); 
}

void State_Paused::Position()
{
	sf::Vector2u windowSize = stateManager->GetContext()->window->GetRenderWindow()->getSize();
	title.SetPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f));
}

void State_Paused::Draw(){
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();
	title.Draw(window);
}

void State_Paused::Key_P(){
	stateManager->SwitchTo(StateType::Game); 
}

void State_Paused::Clicked(sf::Vector2i _mousePos){}