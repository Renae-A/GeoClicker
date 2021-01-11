#include "Spawn.h"

// Constructor that takes a GameObject pointer to assign it the Spawn
Spawn::Spawn(GameObject * newOwner)
{
	owner = newOwner;
	mSpeed = 100;
	timer = 0;
	ownerTransform = owner->getComponent<Transform>();
}

// An update function that updates the Spawn taking deltatime
void Spawn::update(float deltaTime)
{
	// if the spawn is active and enabled then move it in the direction it is facing by the speed specified
	if (owner->getComponent<Spawn>()->active && owner->getComponent<Spawn>()->enabled)
	{
		auto facing = ownerTransform->getGlobalTransform()[1] * deltaTime * mSpeed;
		ownerTransform->translate(facing.x, facing.y);
	}

	// if the spawn is inactive (blue circle captured) 
	else if (owner->getComponent<Spawn>()->active == false)
	{
		// continuously rotate it and scale it down so it shrinks
		for (int i = 0; i < 5; i++)
		{
			ownerTransform->rotate(i);
		}
			ownerTransform->scale(0.95f, 0.95f);	
	}

	// if the spawn is not enable (forzen by snowflake) then add one to the timer for every update
	if (owner->getComponent<Spawn>()->enabled == false)
	{
		owner->getComponent<Spawn>()->timer++;
	}

	// when the timer reaches 500 the spawn is no longer frozen and starts moving again
	if (owner->getComponent<Spawn>()->timer == 500)
		owner->getComponent<Spawn>()->enabled = true;
}

// An update function that draws the Spawn if necessary
void Spawn::draw(aie::Renderer2D* renderer)
{
}
