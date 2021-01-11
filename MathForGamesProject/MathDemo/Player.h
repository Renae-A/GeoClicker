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

class Player : public Component
{
public:
	Player(GameObject* newOwner = nullptr);		// Constructor that takes a GameObject pointer to assign it the Player

	aie::Input* input;							

	float mSpeed;								// The speed of the Player
	bool active = true;							// A bool that allows certain functions to be active when true and other functions when false
	int deathCounter = 0;						// A counter that does 100 updates when the Player dies to display "Game Over" text

protected:
	void update(float deltaTime);				// An update function that updates the Player taking deltatime
	void draw(aie::Renderer2D* renderer);		// An update function that draws the Player if necessary

private:
	float up, down, left, right;				// Floats that decribe up down left and right
	Vector2 wishDir;							// A 2D vector that describes the Players wíshed direction
	Transform* ownerTransform;					// A transform pointer pointing to the Player owner's Transform
		
};