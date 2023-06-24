/**
 * @file GameObject.h
 * @brief Header file for the GameObject class.
 *
 * This header file contains the declaration of the GameObject class,
 * along with member variables and function prototypes.
 */

#pragma once
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "ObjectComponent.h"


 /**
  * @class GameObject
  * @brief Represents a game object that inherits from ObjectComponent and SFML-Transformable.
  *
  * 
  * The SFML-Transformable is used in order to provide position/rotation/scale/origin to the game object.
  *
  * @note GameObject inherits from ObjectComponent and SFML/Graphics/Transformable.
  */
class GameObject
	:public ObjectComponent, public sf::Transformable
{
public:

	/**
	* @brief Default constructor.
	*/
	GameObject()=default;

	/**
	 * @brief Explicit constructor for the GameObject class.
	 * @param name Game object's name.
	 * @param parent Pointer to the parent game object.
	 * @param pos The position of the game object (const sf::Vector2f&).
	 * @param origin The local origin of the game object (const sf::Vector2f&).
	 *				 The origin of an object defines the center point for all transformations (position, scale, rotation).
	 */
	explicit GameObject(const std::string& name="Game Object", ObjectComponent* parent = nullptr,
						const sf::Vector2f& pos = sf::Vector2f(0.0, 0.0), const sf::Vector2f& origin = sf::Vector2f(0.0, 0.0));

	/**
	* @brief Virtual destructor.
	*/
	virtual ~GameObject()=default;

	/**
	* @brief Add a component to the object componets list
	* @param component Pointer to an ObjectComponent.
	*/
	virtual void addComponent(ObjectComponent* component);

	/**
	* @brief Remove a component from the game object.
	* @param name The name of the component or game object to be removed.
	* @param type The type of the component or game object to be removed.
	*/
	virtual void removeComponent(const std::string& name, const ComponentType& type=ComponentType::Null);

	/**
	* @brief Update all the game object's components.
	*/
	virtual void update() override;

	/**
	* @brief Retrieves the game object type.
	* @return GameObject type.
	*/
	virtual ComponentType getType()const override;

protected:
	std::list<std::unique_ptr<ObjectComponent>> m_componets; /// List of uniq pointers to all of the game object's components.
};
