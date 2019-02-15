#include "State_Load.h"
#include "StateManager.h"
#include <fstream>
#include <iostream>

State_Load::State_Load(StateManager* _stateManager)
	: State(_stateManager), selected(0){
	title.SetSize(25);
	title.SetText("LOAD GAME");

	std::string str[2];
	str[0] = "ENTER";
	str[1] = "BACK";
	for (unsigned int i = 0; i < 2; i++)
	{
		button[i].SetLabel(str[i]);
	}
}

void State_Load::Activate(){
	Position();
	loadFiles();
	for (unsigned int i = 0; i < 5; i++){
		choice[i].SetLabel(filenames[i]);
	}
	std::string str[2];
	select(0);
}

void State_Load::Position(){
	sf::Vector2u windowSize = stateManager->GetContext()->window->GetRenderWindow()->getSize();

	sf::Vector2f buttonPos = sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f - 4.0f*(choice[0].GetSize().y));

	title.SetPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 4.0f + 25));

	for (unsigned int i = 0; i < 2; i++)
	{
		button[i].SetPosition(sf::Vector2f(windowSize.x / 2.0f, (0.75f * windowSize.y) - (1 - i)*(button[i].GetSize().y + 10)));
	}
	for (unsigned int i = 0; i < 5; i++){
		choice[i].SetPosition(sf::Vector2f(buttonPos.x, 40 + buttonPos.y + i * choice[0].GetSize().y + 25));
	}
}


void State_Load::Draw(){
	sf::RenderWindow* window = stateManager->GetContext()->window->GetRenderWindow();
	title.Draw(window);
	for (unsigned int i = 0; i < 2; i++)
	{
		button[i].Draw(window);
	}
	for (unsigned int i = 0; i < 5; i++){
		choice[i].Draw(window);
	}
}

void State_Load::Clicked(sf::Vector2i _mousePosition){
	sf::Vector2i mousePos = _mousePosition;
	for (unsigned int i = 0; i < 2; i++)
	{
		if (button[i].Clicked(mousePos)){
			if (i == 0){
				stateManager->SwitchTo(StateType::Game);
				return;
			}
			else if (i == 1){
				stateManager->GetContext()->load.clear();
				stateManager->SwitchTo(StateType::MainMenu);
				return;
			}
			return;
		}
	}
	for (unsigned int i = 0; i < 5; i++){
		if (choice[i].Clicked(mousePos)){
			select(i);
		}
	}
}

void State_Load::loadFiles(){
	std::ifstream iFile("dep\\sa\\list.gc");
	if (!iFile.is_open()){
		std::cout << "couldn't open file" << std::endl 
			<< "saving failed" << std::endl;
		return;
	}
	std::string temp;
	for (unsigned int i = 0; i < 5; i++){
		std::getline(iFile, temp);
		if (temp.empty()){
			break;
		}
		filenames[i] = temp;
	}
	iFile.close();
}

void State_Load::select(int _x){
	if (selected > -1){
		choice[selected].SetColor(sf::Color(0, 128, 128));
	}
	selected = _x;
	if (_x > -1 && _x < 5){
		choice[_x].SetColor(sf::Color(0, 180, 180, 255));
		stateManager->GetContext()->load = filenames[_x];
	}
}