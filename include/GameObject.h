#pragma once
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "ObjectComponent.h"



class GameObject
	:public ObjectComponent, public sf::Transformable
{
public:
	GameObject()=default;	
	explicit GameObject(const sf::Vector2f &pos,const sf::Vector2f &origin= sf::Vector2f(0.0, 0.0));
	virtual ~GameObject()=default;

	virtual void addComponent(ObjectComponent* component);
	virtual void removeComponent(ObjectComponent* component);
	virtual void update() override;

protected:
	std::list<std::unique_ptr<ObjectComponent>> m_componets;
};
