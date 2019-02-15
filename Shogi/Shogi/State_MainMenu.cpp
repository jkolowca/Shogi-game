#include "State_MainMenu.h"
#include "StateManager.h"

State_MainMenu::State_MainMenu(StateManager* _stateManager): State(_stateManager){
	title.SetSize(25);
	title.SetText("MAIN MENU");
	

	std::string str[3];
	str[0] = "PLAY";
	str[1] = "LOAD GAME";
	str[2] = "EXIT";

	for (int i = 0; i < 3; ++i){
		buttons[i].SetLabel(str[i]);
	}
}

void State_MainMenu::Activate(){
	Position();
}

void State_MainMenu::Position(){
	sf::Vector2u windowSize = stateManager->GetContext()->window->GetRenderWindow()->getSize();
	sf::Vector2f buttonPos = sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f - 0.5f*(buttons[0].GetSize().y + 10));

	title.SetPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 4.0f+25));

	for (int i = 0; i < 3; ++i){
		sf::Vector2f buttonPosition(buttonPos.x, buttonPos.y + (i * (buttons[0].GetSize().y + 10))+25);
		buttons[i].SetPosition(buttonPosition);
	}
}

void State_MainMenu::Draw(){
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();
	
	title.Draw(window);
	for(int i = 0; i < 3; ++i){
		buttons[i].Draw(window);
	}
}

void State_MainMenu::Key_Esc(){
	stateManager->GetContext()->window->Close();
}

void State_MainMenu::Clicked(sf::Vector2i _mousePosition){
	sf::Vector2i mousePos = _mousePosition;

	for(int i = 0; i < 3; ++i){
		if(buttons[i].Clicked(mousePos))
		{
			if(i == 0){
				stateManager->SwitchTo(StateType::Game);
			} else if(i == 1){
				stateManager->SwitchTo(StateType::Load);
			} else if(i == 2){
				stateManager->GetContext()->window->Close();
			}
		}
	}
}