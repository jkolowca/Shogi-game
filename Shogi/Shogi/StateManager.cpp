#include "StateManager.h"
#include "State_Game.h"
#include "State_GameOver.h"
#include "State_Intro.h"
#include "State_Load.h"
#include "State_MainMenu.h"
#include "State_Paused.h"
#include "State_Save.h"

StateManager::StateManager(SharedContext* _shared)
	: shared(_shared)
{
	states.push_back(new State_Intro(this));
	states.push_back(new State_MainMenu(this));
	states.push_back(new State_Load(this));
	states.push_back(new State_Save(this));
	states.push_back(new State_Game(this));
	states.push_back(new State_Paused(this));
	states.push_back(new State_GameOver(this));
}

StateManager::~StateManager(){
}


void StateManager::Draw(){
	states[(int)activeState]->Draw();
}

SharedContext* StateManager::GetContext(){ 
	return shared; 
}


State* StateManager::getActiveState() { 
	return states[(int)activeState]; 
}

void StateManager::SwitchTo(StateType _type){
	activeState = _type;
	states[(int)activeState]->Activate();
}