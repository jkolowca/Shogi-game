#include "GameRules.h"

GameRules::GameRules(Game* _game)
	: game(_game), activeStage(pPiece), canBePromoted(nullptr){}
GameRules::~GameRules(){}

void GameRules::ProcessInput(sf::Vector2i _mousePos){
	canBePromoted = nullptr;
	if (activeStage == pPiece) PickPiece(_mousePos);
	else PickPosition(_mousePos);
}

void GameRules::PickPosition(sf::Vector2i _mousePos){
	move.newPosition = game->SquareSelected(_mousePos);
	if (move.newPosition == nullptr){
		ClearMove();
		return;
	}
	if (move.newPosition->IsSelected() == false){
		ClearMove();
		PickPiece(_mousePos);
		return;
	}
	if (move.capturedPiece = move.newPosition->GetPiece()){
		if (move.capturedPiece->IsKing()){
			game->End();
			return;
		}
		game->GetActivePlayer()->CapturePiece(move.capturedPiece);
	}
	CheckPromotion();
	game->GetActivePlayer()->DrawPiece(move.movedPiece);
	game->GetBoard()->MovePiece(move.movedPiece, move.newPosition->GetCoordinates());
	history += move;
	ClearMove();
	game->NewTurn();
}

void GameRules::PickPiece(sf::Vector2i _mousePos){
	move.movedPiece = game->PieceSelected(_mousePos);
	if (move.movedPiece==nullptr){
		return;
	}
	if (move.movedPiece->GetPlayer() != game->GetActivePlayer()->GetId()){
		ClearMove();
		return;
	}
	move.movedPiece->Select();
	if(move.movedPiece->GetAlive()) 
		move.oldPosition = game->SquareSelected(_mousePos);
	game->GetBoard()->HighlightMoves(move.movedPiece);
	activeStage = pPositon;
}

void GameRules::Promote(sf::Vector2i _mousePos){
	if (canBePromoted){
		if (canBePromoted->Clicked(_mousePos))
			canBePromoted->SetPromoted(true);
		move.movedPiece = canBePromoted;
		move.promotion = true;
		history += move;
	}
}

void GameRules::ClearHistory(){
	history.Clear();
}

void GameRules::UndoMove(){
	if (history.IsEmpty()) return;
	move = history.Pop();
	if (move.promotion){
		move.movedPiece->SetPromoted(false);
		canBePromoted = move.movedPiece;
	}
	else{
		if (!move.oldPosition){
			game->GetPlayer(move.movedPiece->GetPlayer())->CapturePiece(move.movedPiece);
		}
		else if (move.capturedPiece){
			game->GetPlayer(move.movedPiece->GetPlayer())->DrawPiece(move.capturedPiece);
			move.capturedPiece->SetPlayer(!(bool)move.movedPiece->GetPlayer());
			game->GetBoard()->MovePiece(move.capturedPiece, move.newPosition->GetCoordinates());
		}
		game->GetBoard()->MovePiece(move.movedPiece, move.oldPosition->GetCoordinates());
		if(!move.promotion) game->NewTurn();
	}
	ClearMove();
}

void GameRules::CheckPromotion(){
	if (move.movedPiece->GetAlive()){
		int row = move.newPosition->GetCoordinates().x;
		if (game->GetActivePlayer()->GetId()){
			if (row == 8 || row == 7 || row == 6)
				canBePromoted = move.movedPiece;
		}
		else if (row == 2 || row == 1 || row == 0)
			canBePromoted = move.movedPiece;
	}
}

void GameRules::ClearMove(){
	activeStage = pPiece;
	game->GetBoard()->Deselect();
	move.movedPiece->Deselect();
	move ={ nullptr, nullptr, nullptr, nullptr, false };
}