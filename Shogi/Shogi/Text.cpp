#include "Text.h"

Text::Text(){
	SetFont("dep\\norwester.otf");
	SetText("");
	SetSize(15);
	SetPosition(sf::Vector2f(0.0f,0.0f));
}
Text::~Text(){}

void Text::Draw(sf::RenderWindow* _window){
	_window->draw(text);
}

void Text::SetFont(const std::string& _font){
	font.loadFromFile(_font);
	text.setFont(font);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
}
void Text::SetSize(unsigned int _size){
	text.setCharacterSize(_size);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
}
void Text::SetPosition(sf::Vector2f _position){
	text.setPosition(_position);
}
void Text::SetText(const std::string& _text){
	text.setString(_text);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
}
void Text::SetColor(sf::Color _color){
	text.setFillColor(_color);
}