#pragma once
#include <string>
#include "Game.h"

class GameLoader{
public:
	GameLoader(Game*);
	~GameLoader();

	/*wczytuje gre z pliku tekstowego*/
	void Load(std::string);
	/*wczytuje automatyczny zapis*/
	void LoadDefault();

	/*zapisuje gre do pliku*/
	void Save(std::string);
private:
	Game* game;
};