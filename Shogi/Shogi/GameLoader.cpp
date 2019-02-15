#include "GameLoader.h"
#include <fstream>
#include <iostream>


GameLoader::GameLoader(Game* _game):game(_game){}
GameLoader::~GameLoader(){}

void GameLoader::Load(std::string _file){
	_file.insert(0, "dep\\sa\\");
	_file.append(".gc");

	std::ifstream iFile(_file, std::ifstream::in);
	if (!iFile.is_open()){
		std::cout << "couldn't open file. starting new game instead..." << std::endl;
		LoadDefault();
		return;
	}
	try {
		iFile >> game;
	}
	catch(...){
		std::cout << "Invalid save file. Starting new game instead..." << std::endl;
		LoadDefault();
	}
	iFile.close();
}

void GameLoader::LoadDefault(){
	Load("default");
}

void GameLoader::Save(std::string _file){
	_file.insert(0, "dep\\sa\\");
	_file.append(".gc");

	std::ofstream oFile(_file, std::ofstream::out|std::ofstream::trunc);
	if (!oFile.is_open()){
		std::cout << "couldn't open file..." << std::endl;
		return;
	}

	oFile << game;

	oFile.close();

	std::ifstream iSave("dep\\sa\\list.gc", std::fstream::in);
	if (!iSave.is_open()){
		std::cout << "couldn't open saved files" << std::endl;
		return;
	}
	std::string temp;
	while (getline(iSave, temp)){
		if (temp == _file) return;
	}
	iSave.close();

	std::ofstream oSave("dep\\sa\\list.gc", std::ofstream::out | std::ofstream::app);
	if (!oSave.is_open()){
		std::cout << "couldn't open saved files" << std::endl;
		return;
	}
	oSave << _file << std::endl;
	oSave.close();
}