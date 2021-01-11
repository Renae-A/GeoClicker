#pragma once
#include <Renderer2D.h>

class Component
{
	friend class GameObject;

public:
	bool enabled = true;								// A bool that allows a component's ability to be stopped if necessary

protected:
	GameObject * owner;									// The owner of the Component
	virtual void update(float deltatime) = 0;			// A pure virtual update function that updates the Component taking deltatime
	virtual void draw(aie::Renderer2D* renderer) = 0;	// A pure virtual update function that draws the Component if necessary
};

