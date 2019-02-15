#include "State_GameOver.h"
#include "StateManager.h"

State_GameOver::State_GameOver(StateManager* _stateManager)
	: State(_stateManager){
	title.SetSize(100);
	title.SetText("GAME OVER");

	button.SetLabel("MAIN MENU");
}

void State_GameOver::Activate()
{
	stateManager->GetContext()->load = "default";
	Position();
}


void State_GameOver::Position(){
	sf::Vector2u windowSize = stateManager->GetContext()->window->GetRenderWindow()->getSize();

	title.SetPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.5f));
	button.SetPosition(sf::Vector2f(windowSize.x / 2.0f, 0.6f * windowSize.y));
}

void State_GameOver::Draw(){
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();
	title.Draw(window);
	button.Draw(window);
}

void State_GameOver::Clicked(sf::Vector2i _mousePosition)
{
	sf::Vector2i mousePos = _mousePosition;

	if (button.Clicked(mousePos))
		stateManager->SwitchTo(StateType::MainMenu);
}