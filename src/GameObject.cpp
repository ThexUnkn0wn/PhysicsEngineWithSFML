#include "../include/GameObject.h"

GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& origin) 
{
	this->sf::Transformable::setPosition(pos);
	this->sf::Transformable::setOrigin(origin);
};