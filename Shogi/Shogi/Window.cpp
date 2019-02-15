#include "Window.h"

Window::Window(const std::string& title, const sf::Vector2u& size)
	: title(title), size(size), defaultSize(size),
	isFullscreen(false), isDone(false){

	sf::Uint32 style = sf::Style::None;
	window.create(sf::VideoMode(size.x, size.y, 32), title, style);
	window.setFramerateLimit(60);
}

Window::~Window(){ 
	window.close(); 
}


void Window::Clear(){ 
	window.clear(sf::Color(0,0,0,255)); 
}

void Window::Display(){ 
	window.display(); 
}

void Window::Update(){
	sf::Event event;
	while(window.pollEvent(event)){
		if (event.type == sf::Event::LostFocus){ eventManager.SetFocus(false); }
		else if (event.type == sf::Event::GainedFocus){ eventManager.SetFocus(true); }
		eventManager.HandleEvent(event);
	}
	eventManager.Update();
}

bool Window::IsDone(){ 
	return isDone; 
}

bool Window::IsFullscreen(){
	return isFullscreen;
}


void Window::ToggleFullscreen(){
	isFullscreen = !isFullscreen;
	window.close();
	Create();
}

void Window::Close(){ 
	isDone = true; 
}


sf::RenderWindow* Window::GetRenderWindow(){ 
	return &window; 
}

EventManager* Window::GetEventManager(){ 
	return &eventManager; 
}

sf::Vector2u Window::GetWindowSize(){
	return size; 
}

void Window::Create(){
	sf::Uint32 style = sf::Style::None;
	size = defaultSize;
	if(isFullscreen)
	{ 
		size = sf::Vector2u(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		style = sf::Style::Fullscreen; 
	}
	window.create(sf::VideoMode(size.x,size.y,32),title,style);
	window.setFramerateLimit(60);
}