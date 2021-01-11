#include "Weapon.h"

// Constructor that takes a GameObject pointer to assign it the Weapon
Weapon::Weapon(GameObject * newOwner)
{
	owner = newOwner;
	mSpeed = 500;
	ownerTransform = owner->getComponent<Transform>();
}

// An update function that updates the Weapon taking deltatime
void Weapon::update(float deltaTime)
{

	aie::Input* input = aie::Input::getInstance();

	// if the weapon is not active (in the power ring) then move it in the direction it is facing by the specified speed
	if (owner->getComponent<Weapon>()->active == false)
	{
		auto facing = ownerTransform->getLocalTransform()[1] * deltaTime * mSpeed;
		ownerTransform->translate(facing.x, facing.y);
	}
}

// An update function that draws the Weapon if necessary
void Weapon::draw(aie::Renderer2D * renderer)
{
}
