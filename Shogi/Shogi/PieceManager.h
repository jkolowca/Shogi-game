#pragma once
#include <vector>
#include "Pawn.h"
#include "Lance.h"
#include "Knight.h"
#include "SGeneral.h"
#include "GGeneral.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "SharedContext.h"

class PieceManager
{
public:
	PieceManager(SharedContext*);
	~PieceManager();

	void load(int(&)[9][9]);

	void draw();
	void select(int);
	void resize();
	int getSelected();
	void movePiece(int, sf::Vector2f, sf::Vector2i);
private:
	std::vector<Piece*> pieces;
	SharedContext* context;
	int selected;

};