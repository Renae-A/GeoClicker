#pragma once
#include <Renderer2D.h>
#include "Component.h"
#include <vector>



class GameObject
{
public:
	GameObject();											// Default constructor
	GameObject(const GameObject& copy);						// Copy constructor
	GameObject(std::vector<Component*> coms);				// A constructor that takes a list of Component pointers
	~GameObject();											// Destructor

	void update(float deltatime);							// An update function that updates the Game Object taking deltatime
	void draw(aie::Renderer2D* renderer);					// An update function that draws the Game Object if necessary
	void addComponent(Component* com);						// addComponent allows the addition of a new component to a GameObject

	template <typename T>									// Template for function getComponent
	T* getComponent()										// Returns a T* component
	{
		for (unsigned int i = 0; i < comList.size(); i++)	// For every component in the list
		{
			Component* comPtr = comList[i];					// Create a pointer to th component
			T* cast = dynamic_cast<T*>(comPtr);				// Type cast the component pointer to type T*

			if (cast != nullptr)							// If cast is empty
			{
				return cast;								
			}
		}
		return nullptr;
	}

private:
	std::vector<Component*> comList;						// The list of Component pointers within the GameObject
};

