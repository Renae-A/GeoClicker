#pragma once
#include "Component.h"
#include <Input.h>
#include <Renderer2D.h>
#include <MathLibrary.h>
#include "GameObject.h"
#include "Transform.h"
#include <Application.h>
#include "Image.h"
#include <ctime>
#include <cstdlib>
#include "GameObject.h"
#include "MathDemoApp.h"
#include <vector>
#include "Player.h"

class Spawn : public Component
{
public:
	Spawn(GameObject* newOwner = nullptr);		// Constructor that takes a GameObject pointer to assign it the Spawn
	
	aie::Input* input;

	float mSpeed;								// The speed of the Spawn
	bool active = true;							// A bool that allows certain functions to be active when true and other functions when false
	int timer = 0;								// A timer for when the Spawn is frozen that count how long it is frozen for
	aie::Texture* blueCircleDeath;				// A texture of when the blue circle is captured

protected:
	void update(float deltaTime);				// An update function that updates the Spawn taking deltatime
	void draw(aie::Renderer2D* renderer);		// An update function that draws the Spawn if necessary
	Transform* ownerTransform;					// A transform pointer pointing to the Spawn owner's Transform
};
