#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "EventManager.h"

#define WINDOWSIZE sf::Vector2u(1500, 900)

class Window{
public:
	Window(const std::string&, const sf::Vector2u&);
	~Window();

	/*czysci okno*/
	void Clear();
	/*wyswietla w oknie wszystko co zostalo w nim do tej pory zrenderowane*/
	void Display();

	void Update();

	/*informuje czy okno zostalo zamkniete*/
	bool IsDone();
	bool IsFullscreen();

	/*zmienia rozmiar okna*/
	void ToggleFullscreen();
	void Close();

	sf::RenderWindow* GetRenderWindow();
	EventManager* GetEventManager();
	sf::Vector2u GetWindowSize();
private:
	/*tworzy okno o zadanych paramterach*/
	void Create();

	sf::RenderWindow window;
	EventManager eventManager;
	sf::Vector2u size;
	sf::Vector2u defaultSize;
	std::string title;
	bool isDone;
	bool isFullscreen;
};