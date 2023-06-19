/**
 * @file ObjectComponent.cpp
 * @brief Implementation file for the ObjectComponent class.
 *
 * This file contains the implementation details of the ObjectComponent class.
 */

#include "../include/ObjectComponent.h"


/**
* @brief Explicit constructor for the ObjectComponent class.
* @param parent Pointer to the parent component or game object.
*/
ObjectComponent::ObjectComponent(ObjectComponent* parent) : m_parent(parent){}

/**
* @brief Virtual destructor.
*/
ObjectComponent::~ObjectComponent()
{
	m_parent = nullptr;
}

/**
* @brief Set parent component or game object.
* @param parent Pointer to the parent component or game object.
*/
void ObjectComponent::setParent(ObjectComponent* parent)
{
	m_parent = parent;
}

/**
* @brief Get parent component or game object.
* @return Pointer to the parent component or game object.
*/
ObjectComponent* ObjectComponent::getParent() const
{
	return m_parent;
}

/**
* @brief Checks if the component is a composite or a leaf.
* @return	True if the component is a composite, false if it is a leaf.
*/
bool ObjectComponent::isComposite() const
{
	return false;
}
