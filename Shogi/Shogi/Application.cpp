#include "Application.h"


Application::Application(): window("SHOGI", WINDOWSIZE), stateManager(&context){
	context.window = &window;
	window.GetEventManager()->SetStateManager(&stateManager);
	stateManager.SwitchTo(StateType::Intro);
}

Application::~Application(){}


void Application::Update(){
	window.Update();
}

void Application::Render(){
	window.Clear();
	stateManager.Draw();
	window.Display();
}

Window* Application::GetWindow(){ return &window; }