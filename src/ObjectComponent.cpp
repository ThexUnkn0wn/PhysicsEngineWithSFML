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
ObjectComponent::ObjectComponent(const std::string& name, ObjectComponent* parent) : m_name(name), m_parent(parent){}

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
* @brief Set the component's name.
* @param name String representing the component's name.
*/
void ObjectComponent::setName(const std::string& name)
{
	m_name = name;
}

/**
* @brief Retrieves the component's name.
* @return The component's name.
*/
std::string ObjectComponent::getName() const
{
	return m_name;
}

/**
* @brief Checks if the component is a composite or a leaf.
* @return	True if the component is a composite, false if it is a leaf.
*/
bool ObjectComponent::isComposite() const
{
	return false;
}
