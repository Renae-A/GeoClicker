#pragma once
#include "Component.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include <font.h>
#include "MathLibrary.h"

using namespace MathLibrary;

class Transform : public Component
{
public:
	~Transform();										// Default destructor
	Transform* getParent() const;						// Returns the Transform pointer to the parent of the current Transform
	size_t childCount() const;							// Returns the number of children the current Transform has
	Transform* getChild(unsigned int index) const;		// Returns a Transform pointer to an index specified child of the current Transform

	void addChild(Transform* child);					// Sets the Transform pointer passed in to a child of the current Transform
	void removeChild(Transform* child);					// Removes the Transform pointer passed in as a child from the current Transform
	void update(float deltaTime);						// An update function that updates the Transform taking deltatime
	void draw(aie::Renderer2D* renderer);				// An update function that draws the Transform if necessary

	const Matrix3& getLocalTransform() const;			// Returns the Matrix3 address of the current Transform's local Transform
	Matrix3 & getLocalTransform();						// Returns the Matrix3 address of the current Transform's local Transform
	const Matrix3& getGlobalTransform() const;			// Returns the Matrix3 address of the current Transform's global Transform
	Matrix3& getGlobalTransform();						// Returns the Matrix3 address of the current Transform's global Transform

	void updateTransform();								// Updates the Transform and its children
	void setPosition(float x, float y);					// Takes in two floats and sets them as position coordinates for the Transform
	void setRotate(float radians);						// Takes in a float to specify the amount of radians the Transform is rotated
	void setScale(float width, float height);			// Takes in two floats and sets them as the length of pixels for height and width for the Transform
	void translate(float x, float y);					// Takes in two floats and sets it to the x and y for the Transform
	void translate(Vector2 vec);						// Takes in a Vector2 and sets it to the x and y for the Transform
	void rotate(float radians);							// Takes in a float to specify the amount of radians the Transform is rotated
	void scale(float width, float height);				// Takes in two floats and sets them as the length of pixels for height and width for the Transform

protected:
	Transform * m_parent = nullptr;						// A Transform pointer to the parent of the current Transform
	std::vector<Transform*> m_children;					// A vector of Transform pointers that are the children of the current Transform
	Matrix3 m_localTransform = Matrix3::identity;		// The Transform's local transform
	Matrix3 m_globalTransform = Matrix3::identity;		// The Transform's global transform
};