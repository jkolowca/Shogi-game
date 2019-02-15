#pragma once
#include "Window.h"
#include "SharedContext.h"
#include "StateManager.h"

class Application{
public:
	Application();
	~Application();

	void Update();
	void Render();

	Window* GetWindow();
private:
	Window window;
	SharedContext context;
	StateManager stateManager;
};