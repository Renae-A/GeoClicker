#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include <string.h>
#include <memory>
#include "GameObject.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <cstdlib>
#include <assert.h>
#include "ctime"
#include "Component.h"
#include "Image.h"
#include "Transform.h"
#include "Player.h"
#include "Spawn.h"
#include "PowerUp.h"
#include "Weapon.h"

class MathDemoApp : public aie::Application {
public:

	MathDemoApp();							// Default Constructor
	virtual ~MathDemoApp();					// A virtual destructor

	virtual bool startup();					// A virtual bool that returns true when start up is complete
	virtual void shutdown();				// A virtual shut down function for the application

	virtual void update(float deltaTime);	// An update function that updates the Application taking deltatime
	virtual void draw();					// An update function that draws the Application if necessary

protected:

	std::vector<GameObject*> scene;			// A vector that contains pointers to all the GameObjects on the screen
	aie::Renderer2D*	m_2dRenderer;		
	aie::Font*			m_font;				

	aie::Texture* redCircle;				// Player sprite
	aie::Texture* redCircleDeath;			// Player sprite when game over
	aie::Texture* blueCircle;				// Spawn sprite to collect in game
	aie::Texture* blueCircleDeath;			// Spawn sprite after collection
	aie::Texture* square;					// Spawn sprite that is to be avoided by the Player
	aie::Texture* barrier;					// PowerUp sprite that is for the barrier
	aie::Texture* bulletRing;				// PowerUp sprite that is for the bullet ring
	aie::Texture* bullet;					// Weapon sprite used when bullet ring is on screen that allows the Player to shoot at squares to remove them
	aie::Texture* iceRing;					// PowerUp sprite that is for the ice ring
	aie::Texture* snowflake;				// Weapon sprite used when ice ring is on screen that allows the Player to shoot at squares and blue circles to freeze them for a limited time


	GameObject* m_redCircle, m_blueCircle, m_square, m_barrier, m_bulletRing, m_bullet, m_iceRing, m_snowflake;

	int scoreNum;							// Half the score amount
	int count = 0;							// A timer for the blue circles death animation
	int scoreCount = 0;						// The Player's score 
	int powerCounter = 0;					// A counter for the amount of blue circles collected before the Playe receives a PowerUp
	int blueCount = 1;						// The amount of blue circles on screen
	int num = -1;							// An integer used for math equations that will be changed during game
	int counter = 0;						// An integer used for math equations that will be changed during game
	std::string score;						// The scoreCount as a string
};