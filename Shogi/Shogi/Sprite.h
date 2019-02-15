#pragma once
#include <SFML/Graphics.hpp>

/*klasa odpowiedzialna za grafiki*/
class Sprite
{
public:
	Sprite();
	Sprite(const std::string&);
	~Sprite();

	void Draw(sf::RenderWindow*);

	void SetColor(sf::Color);
	void SetPosition(sf::Vector2f);
	void SetTexture(const std::string&);
	void RotateTexture(int);

	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
private:
	sf::Texture texture;			//tekstura wyswietlana na obrazku
	sf::Sprite sprite;				//obrazek
};