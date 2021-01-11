#include "Player.h"

using namespace aie;

// ------------------ RED CIRCLE ------------------------

// Constructor that takes a GameObject pointer to assign it the Player
Player::Player(GameObject* newOwner)
{
	owner = newOwner;
	mSpeed = 1000;
	ownerTransform = owner->getComponent<Transform>();
}

// An update function that updates the Player taking deltatime
void Player::update(float deltaTime)
{
	input = aie::Input::getInstance();

	// while the Player is active
	if (owner->getComponent<Player>()->active)
	{
	/*	up = (float)input->isKeyDown(INPUT_KEY_W);
		down = -(float)input->isKeyDown(INPUT_KEY_S);
		left = -(float)input->isKeyDown(INPUT_KEY_A);
		right = (float)input->isKeyDown(INPUT_KEY_D);

		Vector2 getInput(left + right, up + down);*/

		/*wishDir = getInput;
		wishDir.normalise();
		wishDir *= mSpeed;*/
		
		// Allows the mouse position to be the position of the red circle/player
		Vector2 mouseIn(input->getMouseDeltaX(), input->getMouseDeltaY());
		ownerTransform->translate(mouseIn);
	}

	else
	{
		// continuously rotate the red circle and scale it larger so it grows
		for (int i = 0; i < 5; i++)
		{
			ownerTransform->rotate(i);
		}
		ownerTransform->scale(1.15f, 1.15f);
	}

	// when the player hits a square
	if (owner->getComponent<Player>()->active == false)
	{
		// count is a delay to allow time for animation to play
		while (deathCounter != 100)
			deathCounter++;
	}
}

// An update function that draws the Player if necessary
void Player::draw(aie::Renderer2D* renderer)
{
	
}
