#include "State_Save.h"
#include "StateManager.h"

State_Save::State_Save(StateManager* _stateManager): State(_stateManager){
	title.SetSize(25);
	info.SetSize(25);
	entry.SetSize(25);
	title.SetText("SAVE GAME?");
	info.SetText("ENTER SAVE NAME");
	info.SetColor(sf::Color(255, 255, 255, 80));
	button.SetLabel("SAVE");
}


void State_Save::Activate(){ 
	Position(); 
	entry.SetText(stateManager->GetContext()->save);
}

void State_Save::Position(){
	sf::Vector2u windowSize = stateManager->GetContext()->window->GetRenderWindow()->getSize();

	title.SetPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 4.0f));
	entry.SetPosition(sf::Vector2f(windowSize.x / 2.0f, 0.5f * windowSize.y));
	info.SetPosition(sf::Vector2f(windowSize.x / 2.0f, 0.5f * windowSize.y));
	button.SetPosition(sf::Vector2f(windowSize.x / 2.0f, 0.75f * windowSize.y));
}

void State_Save::Draw(){
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();
	title.Draw(window);
	if (stateManager->GetContext()->save.empty()) info.Draw(window);
	entry.Draw(window);
	button.Draw(window);
}

void State_Save::Clicked(sf::Vector2i _mousePosition){
	sf::Vector2i mousePos = _mousePosition;

	if (button.Clicked(mousePos))
		stateManager->SwitchTo(StateType::Game);
}

void State_Save::Key_Esc(){
	stateManager->GetContext()->save.clear();
	stateManager->SwitchTo(StateType::Game);
}

void State_Save::TextEntered(sf::Uint32 _textEntered){
	if (_textEntered == 13){
		stateManager->SwitchTo(StateType::Game);
		return;
	}
	else if (_textEntered == 32 || _textEntered==27) return;
	else if (_textEntered == 8){
		if (!stateManager->GetContext()->save.empty()) stateManager->GetContext()->save.pop_back();
	}
	else stateManager->GetContext()->save +=_textEntered;
	entry.SetText(stateManager->GetContext()->save);
}