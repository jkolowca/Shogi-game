#pragma once
#include <SFML\Graphics.hpp>

class Text{
public:
	Text();
	~Text();

	void Draw(sf::RenderWindow*);

	void SetFont(const std::string&);
	void SetSize(unsigned int);
	void SetPosition(sf::Vector2f);
	void SetText(const std::string&);
	void SetColor(sf::Color);
private:
	sf::Font font;
	sf::Text text;
};