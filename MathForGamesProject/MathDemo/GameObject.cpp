#include "GameObject.h"
#include "Transform.h"

// Default constructor
GameObject::GameObject()
{
	addComponent(new Transform);
}

// Copy constructor
GameObject::GameObject(const GameObject & copy)
{
	comList.clear();
	addComponent(new Transform);
	comList = copy.comList;
}

// A constructor that takes a list of Component pointers
GameObject::GameObject(std::vector<Component*> coms)
{
	comList.clear();
	addComponent(new Transform);
	for (unsigned int i = 0; i < coms.size(); i++)	// for all the components in the vector
	{
		comList.push_back(coms[i]);	// set to component for new GameObject
	}
}

// Destructor
GameObject::~GameObject()
{
}

// An update function that updates the Game Object taking deltatime
void GameObject::update(float deltatime)
{
	for (int i = 0; i < comList.size(); i++)	// for all the components in the vector
	{
		comList[i]->update(deltatime);	// update
	}
}

// An update function that draws the Game Object if necessary
void GameObject::draw(aie::Renderer2D* renderer)
{
	for (int i = 0; i < comList.size(); i++)	// for all the components in the vector
	{
		comList[i]->draw(renderer);	// draw
	}
}

// addComponent allows the addition of a new component to a GameObject
void GameObject::addComponent(Component * com)
{
	com->owner = this;
	comList.push_back(com);
}
