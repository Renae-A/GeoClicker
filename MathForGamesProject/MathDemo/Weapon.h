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

class Weapon : public Component
{
public:
	Weapon(GameObject* newOwner = nullptr);		// Constructor that takes a GameObject pointer to assign it the Weapon

	aie::Input* input;
	float mSpeed;								// The speed of the Weapon
	bool active = true;							// A bool that allows certain functions to be active when true and other functions when false

protected:
	void update(float deltaTime);				// An update function that updates the Weapon taking deltatime
	void draw(aie::Renderer2D* renderer);		// An update function that draws the Weapon if necessary

private:
	Transform * ownerTransform;					// A transform pointer pointing to the Weapon owner's Transform
};
