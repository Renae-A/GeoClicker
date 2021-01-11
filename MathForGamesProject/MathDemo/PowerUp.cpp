#include "PowerUp.h"

using namespace aie;

// Constructor that takes a GameObject pointer to assign it the PowerUp
PowerUp::PowerUp(GameObject * newOwner)
{
	owner = newOwner;
	ownerTransform = owner->getComponent<Transform>();
}

// An update function that updates the PowerUp taking deltatime
void PowerUp::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// if the PowerUp is a barrier or ice ring
	if (owner->getComponent<Image>()->texture->getFilename() == "../bin/textures/barrier.png" ||
		owner->getComponent<Image>()->texture->getFilename() == "../bin/textures/ice-ring.png")
	{
		ownerTransform->rotate(0.5f); // continuously rotate it
	}	

	// if the PowerUp is a bullet ring
	else if (owner->getComponent<Image>()->texture->getFilename() == "../bin/textures/bullet-ring.png")
	{
		// Left arrow key and Q rotate the ring anticlockwise
		if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_Q))
			ownerTransform->rotate(deltaTime * 2);
		// Right arrow key and E rotate the ring clockwise
		if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_E))
			ownerTransform->rotate(-deltaTime * 2);
	}

}

// An update function that draws the PowerUp if necessary
void PowerUp::draw(aie::Renderer2D * renderer)
{
}
