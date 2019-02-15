#pragma once
#include <string>
#include "Window.h"

/*informacje dzielone w aplikacji*/
struct SharedContext
{
	Window* window;
	std::string load;					//nazwa pliku do wczytania
	std::string save;					//nazwa pliku do zapisu
};