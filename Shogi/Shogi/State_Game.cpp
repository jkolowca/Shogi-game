#include "State_Game.h"
#include "StateManager.h"

State_Game::State_Game(StateManager* _stateManager)
	: State(_stateManager), rules(&game), loader(&game){
	for (unsigned int i = 0; i < 2; i++){						//przygotowanie przycisków
		buttons[i].SetFont("dep\\norwester.otf", 25);
		buttons[i].SetSize(sf::Vector2f(60,60));
	}
	buttons[0].SetLabel("Undo");
	buttons[1].SetLabel("Save");
	buttons[0].SetColor(sf::Color(0,0,0,0));
	buttons[1].SetColor(sf::Color(0,0,0,0));

	loader.LoadDefault();										//wczytanie nowej gry
}

void State_Game::Activate(){ 
	Position();													//wazne! inaczej bledy przy zmianie rozmiaru okna
	if (!stateManager->GetContext()->load.empty()){				
		game.Clear();											//czysci aktualny stan gry
		rules.ClearHistory();
		loader.Load(stateManager->GetContext()->load);			//wczytuje wybrany zapis
		stateManager->GetContext()->load.clear();
	}
	else if (!stateManager->GetContext()->save.empty()){		
		loader.Save(stateManager->GetContext()->save);			//zapisuje pod wybrana nazwa
		stateManager->GetContext()->save.clear();
	}
}

void State_Game::Position(){									//ustawia pozycje elementow w oknie
	sf::Vector2u size = stateManager->GetContext()->window->GetWindowSize();
	game.Position(size);
	buttons[0].SetPosition(sf::Vector2f(size.x-2.5f*buttons[1].GetSize().x, buttons[1].GetSize().y));
	buttons[1].SetPosition(sf::Vector2f(size.x-buttons[1].GetSize().x, buttons[1].GetSize().y));
}

void State_Game::Draw()
{
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();
	game.Draw(window);
	buttons[0].Draw(window);
	buttons[1].Draw(window);
}

void State_Game::Clicked(sf::Vector2i _mousePosition){
	if (buttons[1].Clicked(_mousePosition)){					//reaguje na wcisniecie przyciskow
		stateManager->SwitchTo(StateType::Save);
	}
	else if (buttons[0].Clicked(_mousePosition)){
		rules.UndoMove();
	}
	rules.ProcessInput(_mousePosition);							//wprowadza zmiany w grze
	if (!game.IsPlaying())
		stateManager->SwitchTo(StateType::GameOver);
}

void State_Game::RightClicked(sf::Vector2i _mousePosition){
	rules.Promote(_mousePosition);
}

void State_Game::Key_P(){
	stateManager->SwitchTo(StateType::Paused); 
}