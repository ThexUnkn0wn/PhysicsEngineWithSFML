/**
 * @file ObjectComponent.h
 * @brief Header file for the ObjectComponent class.
 *
 * This header file contains the declaration of the ObjectComponent class,
 * along with member variables and function prototypes.
 */

#pragma once

 /**
  * @class ObjectComponent
  * @brief Represents a game object component.
  *
  * This is an abstract class that defines the interface for game object components.
  * Derived classes must implement the pure virtual function update().
  */
class ObjectComponent
{
public:
	/**
	 * @brief Pure virtual function for updating the component object.
	 */
	virtual void update() = 0;

	/**
	 * @brief Explicit constructor for the ObjectComponent class.
	 * @param parent Pointer to the parent component or game object.
	 */
	explicit ObjectComponent(ObjectComponent* parent = nullptr);

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
	* @brief Checks if the component is a composite or a leaf.
	* @return	True if the component is a composite, false if it is a leaf.
	*/
	virtual bool isComposite() const;


private:
	ObjectComponent* m_parent; /// Pointer to the parent component or game object.

};