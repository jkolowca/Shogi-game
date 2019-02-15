#include "PieceManager.h"


PieceManager::PieceManager(SharedContext* _context) : context(_context), selected(-1) {

	sf::RenderWindow* window = context->window->GetRenderWindow();
	for (unsigned int i = 0; i < 2; i++)
	{
		pieces.push_back(new Lance);
		pieces.push_back(new Knight);
		pieces.push_back(new SGeneral);
		pieces.push_back(new GGeneral);
		pieces.push_back(new King);
		pieces.push_back(new GGeneral);
		pieces.push_back(new SGeneral);
		pieces.push_back(new Knight);
		pieces.push_back(new Lance);
		pieces.push_back(new Rook);
		pieces.push_back(new Bishop);
		for (unsigned int i = 0; i < 9; i++){
			pieces.push_back(new Pawn);
		}
	}
	for (unsigned int i = 0; i < 2; i++){
		for (unsigned int j = 0; j < 20; j++){
			pieces[j]->setPlayer(i);
		}
	}
}

PieceManager::~PieceManager() {
	for (std::vector<Piece*>::iterator i = pieces.begin(); i != pieces.end(); ++i){
		delete *i;
	}
}

void PieceManager::load(int(& _board)[9][9]) {
	for (unsigned int i = 0; i < 9; i++) {
		for (unsigned int j = 0; j < 9; j++) {
			if (_board[i][j] != -1)
				pieces[_board[i][j]]->setPosition(sf::Vector2f(context->window->GetWindowSize().x / 2.0f, context->window->GetWindowSize().y / 2.0f), sf::Vector2i(i, j));
		}
	}
}

void PieceManager::resize() {
	sf::RenderWindow* window = context->window->GetRenderWindow();
	for (unsigned int i = 0; i < 40; i++) {
		pieces[i]->resize(window);
	}
}
void PieceManager::select(int x) {
	if (selected != -1)
		pieces[selected]->deselect();
	if(x!=-1)
		pieces[x]->select();
		selected = x;
}
void PieceManager::draw()
{
	sf::RenderWindow* window = context->window->GetRenderWindow();
	for (unsigned int i = 0; i < 40;i++) {
		pieces[i]->draw(window);
	}
}

void PieceManager::movePiece(int _piece, sf::Vector2f _boardPosition, sf::Vector2i _position) {
	pieces[_piece]->setPosition(_boardPosition, _position);
}

int PieceManager::getSelected()
{
	return selected;
}