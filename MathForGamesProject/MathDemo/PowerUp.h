#pragma once
#include "Component.h"
#include <Input.h>
#include <Renderer2D.h>
#include <MathLibrary.h>
#include "MathDemoApp.h"
#include "GameObject.h"
#include "Transform.h"
#include <Application.h>

using namespace MathLibrary;

class PowerUp : public Component	
{
public:
	PowerUp(GameObject* newOwner = nullptr);		// Constructor that takes a GameObject pointer to assign it the PowerUp

	aie::Input* input;
	int reloadTimer = 0;							// A counter of blue circles captures before a new Weapon is reloaded back into the PowerUp
	bool active = true;								// A bool that allows certain functions to be active when true and other functions when false

protected:
	void update(float deltaTime);					// An update function that updates the PowerUp taking deltatime
	void draw(aie::Renderer2D* renderer);			// An update function that draws the PowerUp if necessary

private:
	Transform* ownerTransform;						// A transform pointer pointing to the PowerUp owner's Transform
};
