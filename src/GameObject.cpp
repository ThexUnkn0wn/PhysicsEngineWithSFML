/**
 * @file GameObject.cpp
 * @brief Implementation file for the GameObject class.
 *
 * This file contains the implementation details of the GameObject class.
 */

#include "../include/GameObject.h"

/**
* @brief Explicit constructor for the GameObject class.
* @param name Game object's name.
* @param parent Pointer to the parent game object.
* @param pos The position of the game object (const sf::Vector2f&).
* @param origin The local origin of the game object (const sf::Vector2f&).
*/
GameObject::GameObject(const std::string& name, ObjectComponent* parent, const sf::Vector2f& pos, const sf::Vector2f& origin)
	: ObjectComponent(name,parent)
{
	this->sf::Transformable::setPosition(pos);
	this->sf::Transformable::setOrigin(origin);
}
void GameObject::addComponent(ObjectComponent* component)
{
}
void GameObject::removeComponent(const std::string& name, const ComponentType& type)
{
}

void GameObject::update()
{
}
ComponentType GameObject::getType() const
{
	return ComponentType::GameObject;
}
;