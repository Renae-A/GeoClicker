#include "Transform.h"

// Default destructor
Transform::~Transform()
{
	// detach from parent 
	if (m_parent != nullptr)
		m_parent->removeChild(this);

	// remove all children 
	for (auto child : m_children)
		child->m_parent = nullptr;
}

// Returns the Transform pointer to the parent of the current Transform
Transform * Transform::getParent() const
{
	return m_parent;
}

// Returns the number of children the current Transform has
size_t Transform::childCount() const
{
	return m_children.size();
}

// Returns a Transform pointer to an index specified child of the current Transform
Transform * Transform::getChild(unsigned int index) const
{
	return m_children[index];
}

// Sets the Transform pointer passed in to a child of the current Transform
void Transform::addChild(Transform * child)
{
	// make sure it doesn't have a parent already 
	assert(child->m_parent == nullptr);

	// assign "this as parent 
	child->m_parent = this;

	// add new child to collection 
	m_children.push_back(child);
}

// Removes the Transform pointer passed in as a child from the current Transform
void Transform::removeChild(Transform * child)
{
	// find the child in the collection 
	auto iter = std::find(m_children.begin(), m_children.end(), child);

	// if found, remove it 
	if (iter != m_children.end())
	{
		m_children.erase(iter);
		// also unassign parent 
		child->m_parent = nullptr;
	}
}

// An update function that updates the Transform taking deltatime
void Transform::update(float deltaTime)
{
	// update children 
	for (auto child : m_children)
		child->update(deltaTime);
}

// An update function that draws the Transform if necessary
void Transform::draw(aie::Renderer2D * renderer)
{

	// draw children 
	for (auto child : m_children)
		child->draw(renderer);
}

// Returns the Matrix3 address of the current Transform's local Transform
const Matrix3 & Transform::getLocalTransform() const
{
	return m_localTransform;
}

// Returns the Matrix3 address of the current Transform's local Transform
Matrix3 & Transform::getLocalTransform()
{
	return m_localTransform;
}

// Returns the Matrix3 address of the current Transform's global Transform
const Matrix3 & Transform::getGlobalTransform() const
{
	return m_globalTransform;
}

// Returns the Matrix3 address of the current Transform's global Transform
Matrix3 & Transform::getGlobalTransform()
{
	return m_globalTransform;
}

// Updates the Transform and its children
void Transform::updateTransform()
{
	if (m_parent != nullptr)
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	else
		m_globalTransform = m_localTransform;
	for (auto child : m_children)
		child->updateTransform();
}

// Takes in two floats and sets them as position coordinates for the Transform
void Transform::setPosition(float x, float y)
{
	m_localTransform[2] = { x, y, 1 };
	updateTransform();
}

// Takes in a float to specify the amount of radians the Transform is rotated
void Transform::setRotate(float radians)
{
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

// Takes in two floats and sets them as the length of pixels for height and width for the Transform
void Transform::setScale(float width, float height)
{
	m_localTransform.setScaled(width, height, 1);
	updateTransform();
}

// Takes in two floats and sets it to the x and y for the Transform
void Transform::translate(float x, float y)
{
	m_localTransform.translate(x, y);
	updateTransform();
}

// Takes in a Vector2 and sets it to the x and y for the Transform
void Transform::translate(Vector2 vec)
{
	m_localTransform.translate(vec.x, vec.y);
	updateTransform();
}

// Takes in a float to specify the amount of radians the Transform is rotated
void Transform::rotate(float radians)
{
	m_localTransform.rotateZ(radians);
	updateTransform();
}

// Takes in two floats and sets them as the length of pixels for height and width for the Transform
void Transform::scale(float width, float height)
{
	m_localTransform.scale(width, height, 1);
	updateTransform();
}
