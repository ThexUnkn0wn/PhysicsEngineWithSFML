/**
 * @file ObjectComponent.h
 * @brief Header file for the ObjectComponent class.
 *
 * This header file contains the declaration of the ObjectComponent class,
 * along with member variables and function prototypes.
 */

#pragma once
#include <string>
#include "ComponentType.h"

 /**
  * @class ObjectComponent
  * @brief Represents a game object component.
  *
  * This is an abstract class that defines the interface for game object components.
  * Derived classes must implement the pure virtual function update() and getType().
  */
class ObjectComponent
{
public:
	/**
	 * @brief Pure virtual function for updating the component object.
	 */
	virtual void update() = 0;

	/**
	 * @brief Pure virtual function that retrieves the type of the component object.
	 * @return The component type.
	 */
	virtual ComponentType getType() const = 0;

	/**
	 * @brief Explicit constructor for the ObjectComponent class.
	 * @param name String representing the component's name.
	 * @param parent Pointer to the parent component or game object.
	 */
	explicit ObjectComponent(const std::string& name, ObjectComponent* parent = nullptr);

	/**
	* @brief Virtual destructor.
	*/
	virtual ~ObjectComponent();

	/**
	* @brief Set parent component or game object.
	* @param parent Pointer to the parent component or game object.
	*/
	void setParent(ObjectComponent* parent);

	/**
	* @brief Get parent component or game object.
	* @return Pointer to the parent component or game object.
	*/
	ObjectComponent* getParent() const;

	/**
	* @brief Set the component's name.
	* @param name String representing the component's name.
	*/
	void setName(const std::string& name);

	/**
	* @brief Retrieves the component's name.
	* @return The component's name.
	*/
	std::string getName() const;

	/**
	* @brief Checks if the component is a composite or a leaf.
	* @return	True if the component is a composite, false if it is a leaf.
	*/
	virtual bool isComposite() const;


private:
	ObjectComponent* m_parent;	/// Pointer to the parent component or game object.
	std::string m_name;			/// Componet's name.

};