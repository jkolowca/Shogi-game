#include "Sprite.h"

Sprite::Sprite(){}

Sprite::Sprite(const std::string& _file){
	SetTexture(_file);
}

Sprite::~Sprite(){}

void Sprite::Draw(sf::RenderWindow* _window){
	_window->draw(sprite);
}

void Sprite::SetColor(sf::Color _color){
	sprite.setColor(_color);
}

void Sprite::SetPosition(sf::Vector2f _position){
	sprite.setPosition(_position);
}

void Sprite::SetTexture(const std::string& _file){
	texture.loadFromFile(_file);
	sprite.setTexture(texture);
	sprite.setOrigin(GetSize().x / 2.0f, GetSize().y / 2.0f);
}

void Sprite::RotateTexture(int _x){
	sprite.setRotation(_x * 180.0f);
}

sf::Vector2f Sprite::GetPosition(){
	return sprite.getPosition();
}

sf::Vector2f Sprite::GetSize(){
	return sf::Vector2f(texture.getSize().x*sprite.getScale().x, texture.getSize().y*sprite.getScale().y);
}