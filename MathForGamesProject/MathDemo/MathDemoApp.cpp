#include "MathDemoApp.h"

MathDemoApp::MathDemoApp() {}

MathDemoApp::~MathDemoApp() {}

bool MathDemoApp::startup() {

	m_2dRenderer = new aie::Renderer2D();
	srand((unsigned)time(nullptr));

	// makes the cursor invisible
	setShowCursor(false);

	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	// load the sprites in 
	redCircle = new aie::Texture("../bin/textures/circle.png");
	redCircleDeath = new aie::Texture("../bin/textures/red-circle-death.png");
	blueCircle = new aie::Texture("../bin/textures/blue.png");
	blueCircleDeath = new aie::Texture("../bin/textures/blue-circle-death.png");
	square = new aie::Texture("../bin/textures/square.png");
	barrier = new aie::Texture("../bin/textures/barrier.png");
	bulletRing = new aie::Texture("../bin/textures/bullet-ring.png");
	bullet = new aie::Texture("../bin/textures/arrow.png");
	snowflake = new aie::Texture("../bin/textures/snowflake.png");
	iceRing = new aie::Texture("../bin/textures/ice-ring.png");

	// check file name is correct
	assert(redCircle->getFilename() == "../bin/textures/circle.png");

	// ------------------ RED CIRCLE ------------------------

	// Create the red circle game object
	GameObject* m_redCircle = new GameObject;

	// Set image and size
	m_redCircle->addComponent(new Image(90, 90, redCircle, m_redCircle));

	// Make it a player
	m_redCircle->addComponent(new Player(m_redCircle));

	// center the red circle
	m_redCircle->getComponent<Transform>()->setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);

	// push into scene
	scene.push_back(m_redCircle);

	// ------------------ BLUE CIRCLE ------------------------

	// Create the blue circle game object
	GameObject* m_blueCircle = new GameObject;

	// Set image and size
	m_blueCircle->addComponent(new Image(25, 25, blueCircle, m_blueCircle));

	// Make it a spawn
	m_blueCircle->addComponent(new Spawn(m_blueCircle));

	// Randomise its set rotation
	m_blueCircle->getComponent<Transform>()->rotate(rand() % 5);

	// randomise the blue circle's position
	m_blueCircle->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

	// push into scene
	scene.push_back(m_blueCircle);

	return true;
}

void MathDemoApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void MathDemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// scoreCount to string
	score = std::to_string(scoreCount);

	// scoreNum
	scoreNum = scoreCount / 10;

	// a counter for math use 
	if (counter == 10)
	{
		counter = 0;
		num++;
	}

	// ------------------ BLUE CIRCLE AND SQUARE RATIO DUE TO SCORE ------------------------

	// if the player has no power ring
	if (scene[0]->getComponent<Transform>()->childCount() == 0)
	{
		// if scoreCount is a multiple of ten and the scene (not including the red circle and the extra blue circle) is less than the scoreCount divided by 10 
		if (scoreNum > 0 && (blueCount - 1) < scoreNum)
		{
			// ------------------ BLUE CIRCLE ------------------------

			// Create the blue circle game object
			GameObject* m_blueCircle = new GameObject;

			// Set image and size
			m_blueCircle->addComponent(new Image(25, 25, blueCircle, m_blueCircle));

			// Make it a spawn
			m_blueCircle->addComponent(new Spawn(m_blueCircle));

			// Randomise its set rotation
			m_blueCircle->getComponent<Transform>()->rotate(rand() % 5);

			// randomise the blue circle's position
			m_blueCircle->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

			// Increase the speed of the circle (x3)
			m_blueCircle->getComponent<Spawn>()->mSpeed += scoreCount * 3;

			// push into scene
			scene.push_back(m_blueCircle);

			blueCount++;

			// ------------------ SQUARE ------------------------

			// Create the square game object
			GameObject* m_square = new GameObject;

			// Set image and size
			m_square->addComponent(new Image(25, 25, square, m_square));

			// Make it a spawn
			m_square->addComponent(new Spawn(m_square));

			// randomise the direction of the square vertical or horizontal
			if ((rand() % 2 == 1))
				m_square->getComponent<Transform>()->rotate(1.5708f);

			// randomise the purple square's position
			m_square->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

			// push into scene
			scene.push_back(m_square);
		}
	}
	// if the player has a power ring with no weapon
	else if (scene[0]->getComponent<Transform>()->getChild(0)->childCount() == 0)
	{
		// if scoreCount is a multiple of ten and the scene (not including the red circle, power ring and the extra blue circle) is less than the scoreCount divided by 10 
		if (scoreNum > 0 && (blueCount + 1 - 2) < scoreNum)
		{
			// ------------------ BLUE CIRCLE ------------------------

			// Create the blue circle game object
			GameObject* m_blueCircle = new GameObject;

			// Set image and size
			m_blueCircle->addComponent(new Image(25, 25, blueCircle, m_blueCircle));

			// Make it a spawn
			m_blueCircle->addComponent(new Spawn(m_blueCircle));

			// Randomise its set rotation
			m_blueCircle->getComponent<Transform>()->rotate(rand() % 5);

			// randomise the blue circle's position
			m_blueCircle->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

			// Increase the speed of the circle (x3)
			m_blueCircle->getComponent<Spawn>()->mSpeed += scoreCount * 3;

			// push into scene
			scene.push_back(m_blueCircle);

			blueCount++;

			// ------------------ SQUARE ------------------------

			// Create the square game object
			GameObject* m_square = new GameObject;

			// Set image and size
			m_square->addComponent(new Image(25, 25, square, m_square));

			// Make it a spawn
			m_square->addComponent(new Spawn(m_square));

			// randomise the direction of the square vertical or horizontal
			if ((rand() % 2 == 1))
				m_square->getComponent<Transform>()->rotate(1.5708f);

			// randomise the purple square's position
			m_square->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

			// push into scene
			scene.push_back(m_square);
		}
	}
	// if the player has a power ring and a weapon
	else if (scene[0]->getComponent<Transform>()->getChild(0)->childCount() == 1)
	{
		// if scoreCount is a multiple of ten and the scene (not including the red circle, power ring, weapon and the extra blue circle) is less than the scoreCount divided by 10 
		if (scoreNum > 0 && (blueCount + 1 + num) < ((scoreNum * 2) + 1))
		{
			// ------------------ BLUE CIRCLE ------------------------
	
			// Create the blue circle game object
			GameObject* m_blueCircle = new GameObject;

			// Set image and size
			m_blueCircle->addComponent(new Image(25, 25, blueCircle, m_blueCircle));

			// Make it a spawn
			m_blueCircle->addComponent(new Spawn(m_blueCircle));

			// Randomise its set rotation
			m_blueCircle->getComponent<Transform>()->rotate(rand() % 5);

			// randomise the blue circle's position
			m_blueCircle->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

			// Increase the speed of the circle (x3)
			m_blueCircle->getComponent<Spawn>()->mSpeed += scoreCount * 3;

			// push into scene
			scene.push_back(m_blueCircle);

			blueCount++;

			// ------------------ SQUARE ------------------------

			// Create the square game object
			GameObject* m_square = new GameObject;

			// Set image and size
			m_square->addComponent(new Image(25, 25, square, m_square));

			// Make it a spawn
			m_square->addComponent(new Spawn(m_square));

			// randomise the direction of the square vertical or horizontal
			if ((rand() % 2 == 1))
				m_square->getComponent<Transform>()->rotate(1.5708f);

			// randomise the purple square's position
			m_square->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

			// push into scene
			scene.push_back(m_square);
		}
	}
	

	// ------------------ CAPTURING A BLUE CIRCLE ------------------------

	// if the left mouse button is clicked
	if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
	{
		// for every game object
		for (unsigned int i = 0; i < scene.size(); i++)
		{
			// if current game object is a blue circle
			if (scene[i]->getComponent<Image>()->texture == blueCircle)
			{
				// if the blue circle is within the red circle's ring on the x axis
				if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x >
					(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x - scene[i]->getComponent<Image>()->width) &&
					scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x <
					(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x + scene[i]->getComponent<Image>()->width))
				{
					// if the blue circle is within the red circle's ring on the y axis
					if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y >
						(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y - scene[i]->getComponent<Image>()->width) &&
						scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y <
						(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y + scene[i]->getComponent<Image>()->width))

						// if the blue circle is active
						if (scene[i]->getComponent<Spawn>()->active)
						{
							scoreCount++;															// add 1 to score 
							counter++;																// add 1 to math counter
							powerCounter++;															// add 1 to powerCounter
							scene[i]->getComponent<Image>()->texture = blueCircleDeath;				// blue circle texture changes to death texture
							scene[i]->getComponent<Spawn>()->active = false;						// stops it from adding more to score

							// for every game object in the scene
							for (unsigned int j = 0; j < scene.size(); j++)
							{
								if (scene[j]->getComponent<Image>()->texture == bulletRing || scene[j]->getComponent<Image>()->texture == iceRing)	// if it is a bullet ring or ice ring
								{
									if (scene[j]->getComponent<Transform>()->childCount() == 0)	// if it doesn't have a weapon
										scene[j]->getComponent<PowerUp>()->reloadTimer++;	// add one to the reload timer
								}
							}
						}
				}
			}
		}
	}

	// ------------------ MOVING THE RED CIRCLE OFF THE SCREEN ------------------------

	// if red circle moves off the right side of the screen, keep it at that position it was last in
	if (scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x > getWindowWidth())
	{
		scene[0]->getComponent<Transform>()->setPosition(getWindowWidth(), scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y);
	}

	// if red circle moves off the left side of the screen, keep it at that position it was last in
	if (scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x < 0)
	{
		scene[0]->getComponent<Transform>()->setPosition(0, scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y);
	}

	// if red circle moves off the top of the screen, keep it at that position it was last in
	if (scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y > getWindowHeight())
	{
		scene[0]->getComponent<Transform>()->setPosition(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x, getWindowHeight());
	}

	// if red circle moves off the bottom of the screen, keep it at that position it was last in
	if (scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y < 0)
	{
		scene[0]->getComponent<Transform>()->setPosition(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x, 0);
	}

	// ------------------ RESULT OF THE DEATH OF A BLUE CIRCLE ------------------------

	// deleting blue circles after death allowing a delay after death animation
	// if there are more than just the player in the scene
	if (scene.size() > 1)
	{
		// for every game object in the scene
		for (unsigned int i = 0; i < scene.size(); i++)
		{
			// if the current game object is a "dead" blue circle
			if (scene[i]->getComponent<Image>()->texture == blueCircleDeath)
			{
				// if this game object is not active
				if (scene[i]->getComponent<Spawn>()->active == false)
				{
					// count creates a delay for a couple of seconds to allow the animation to occur
					count++;
					// when count is equal to 100
					if (count == 100)
					{
						scene.erase(scene.begin() + i);		// erase the current blue circle
						count = 0;							// resets the count to 0

						// ------------------ BLUE CIRCLE ------------------------

						// Create the blue circle game object
						GameObject* m_blueCircle = new GameObject;

						// Set image and size
						m_blueCircle->addComponent(new Image(25, 25, blueCircle, m_blueCircle));

						// Make it a spawn
						m_blueCircle->addComponent(new Spawn(m_blueCircle));

						// Randomise its set rotation
						m_blueCircle->getComponent<Transform>()->rotate(rand() % 5);

						// randomise the blue circle's position
						m_blueCircle->getComponent<Transform>()->setPosition((rand() % getWindowWidth()), (rand() % getWindowHeight()));

						// Increase the speed of the circle (x3)
						m_blueCircle->getComponent<Spawn>()->mSpeed += scoreCount * 3;

						// push into scene
						scene.push_back(m_blueCircle);
					}
				}
			}
		}
	}

	// ------------------ BOUNCE COLLISION AGAINST WALLS FOR BLUE CIRCLES OR SQUARES (SPAWN) ------------------------

	// if the scene contains more than just the player
	if (scene.size() > 1)
	{
		// for every game object in the scene
		for (unsigned int i = 0; i < scene.size(); i++)
		{
			// if the current game object is a Spawn (blue circle or a square)
			if (scene[i]->getComponent<Spawn>() != nullptr)
			{
				// if spawn moves off the right side of the screen, move it to the left side at the same y axis it was at beforehand (bounce off edge of screen)
				if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x > getWindowWidth())
				{
					// reverse the x component of our velocity (which is the y-axis of our local transform)
					// IF we're moving right. If not, keep moving left
					if (scene[i]->getComponent<Transform>()->getLocalTransform()[1].x > 0)
					{
						scene[i]->getComponent<Transform>()->getLocalTransform()[1].x *= -1;
						scene[i]->getComponent<Transform>()->getLocalTransform()[0].y *= -1;
					}
				}

				// if spawn moves off the left side of the screen, move it to the right side at the same y axis it was at beforehand (bounce off edge of screen)
				if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x < 0)
				{
					// reverse the x component of our velocity (which is the y-axis of our local transform)
					// IF we're moving left. If not, keep moving right
					if (scene[i]->getComponent<Transform>()->getLocalTransform()[1].x < 0)
					{
						scene[i]->getComponent<Transform>()->getLocalTransform()[1].x *= -1;
						scene[i]->getComponent<Transform>()->getLocalTransform()[0].y *= -1;
					}
				}

				// if spawn moves off the top of the screen, move it to the bottom of screen at the same x axis it was at beforehand (bounce off edge of screen)
				if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y > getWindowHeight())
				{
					// reverse the y component of our velocity (which is the x-axis of our local transform)
					// IF we're moving up. If not, keep moving down
					if (scene[i]->getComponent<Transform>()->getLocalTransform()[1].y > 0)
					{
						scene[i]->getComponent<Transform>()->getLocalTransform()[1].y *= -1;
						scene[i]->getComponent<Transform>()->getLocalTransform()[0].x *= -1;
					}
				}

				// if spawn moves off the bottom of the screen, move it to the top of screen at the same x axis it was at beforehand (bounce off edge of screen)
				if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y < 0)
				{
					// reverse the y component of our velocity (which is the x-axis of our local transform)
					// IF we're moving down. If not, keep moving up
					if (scene[i]->getComponent<Transform>()->getLocalTransform()[1].y < 0)
					{
						scene[i]->getComponent<Transform>()->getLocalTransform()[1].y *= -1;
						scene[i]->getComponent<Transform>()->getLocalTransform()[0].x *= -1;
					}
				}
			}
		}
	}

	// ------------------ SQUARE COMES IN CONTACT WITH RED CIRCLE ------------------------

	// if the square touches the red circle, then game over
	// for every game object in the scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// if the current game object is a square
		if (scene[i]->getComponent<Image>()->texture == square)
		{
			// if the square's x position touches the ring
			if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x >
				(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x - 45) &&
				scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x <
				(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x + 45))
			{
				// if the square's y position touches the ring
				if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y >
					(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y - 45) &&
					scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y <
					(scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y + 45))

					// if the square is active
					if (scene[i]->getComponent<Spawn>()->active)
					{
						scene[0]->getComponent<Image>()->texture = redCircleDeath;		// red circle texture changes (death)
						scene[0]->getComponent<Player>()->active = false;				// set the player to inactive (game over)
					}
			}
		}
	}

	// ------------------ ADDING A POWER RING ------------------------

	// if the player has a power ring
	if (scene[0]->getComponent<Transform>()->childCount() == 1)
	{
		powerCounter = 0;	// set the power counter to 0
	}

	// if the power counter is at 15 and the player has no power ring
	else if (powerCounter == 15 && scene[0]->getComponent<Transform>()->childCount() == 0)
	{
		int power = rand() % 3;	// Randomise the possiblility to get any of the power rings
		if (power == 1)
		{
			// Create the barrier game object
			GameObject* m_barrier = new GameObject;

			// Set image and size
			m_barrier->addComponent(new Image(175, 175, barrier, m_barrier));

			// Make it a PowerUp
			m_barrier->addComponent(new PowerUp(m_barrier));

			// push into scene
			scene.push_back(m_barrier);

			// set it to child of player
			scene[0]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

			// reset power counter
			powerCounter = 0;
		}
		else if (power == 2)
		{
			// Create the bullet ring game object
			GameObject* m_bulletRing = new GameObject;

			// Set image and size
			m_bulletRing->addComponent(new Image(175, 175, bulletRing, m_bulletRing));

			// Make it a PowerUp
			m_bulletRing->addComponent(new PowerUp(m_bulletRing));

			// push into scene
			scene.push_back(m_bulletRing);

			// set it to child of player
			scene[0]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

			// scale to fit around player
			m_bulletRing->getComponent<Transform>()->scale(0.8f, 0.8f);

			// Create the bullet game object
			GameObject* m_bullet = new GameObject;

			// Set image and size
			m_bullet->addComponent(new Image(30, 30, bullet, m_bullet));

			// Make it a Weapon
			m_bullet->addComponent(new Weapon(m_bullet));

			// push into scene
			scene.push_back(m_bullet);

			// set it to child of power ring
			scene[scene.size() - 2]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

			// reset power counter
			powerCounter = 0;
		}
		else
		{
			{
				// Create the ice ring game object
				GameObject* m_iceRing = new GameObject;

				// Set image and size
				m_iceRing->addComponent(new Image(175, 175, iceRing, m_iceRing));

				// Make it a PowerUp
				m_iceRing->addComponent(new PowerUp(m_iceRing));

				// push into scene
				scene.push_back(m_iceRing);

				// set it to child of player
				scene[0]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

				// scale to fit around player
				m_iceRing->getComponent<Transform>()->scale(0.8f, 0.8f);

				// Create the snowflake object
				GameObject* m_snowflake = new GameObject;

				// Set image and size
				m_snowflake->addComponent(new Image(1115, 1275, snowflake, m_snowflake));

				// scale to fit within ring
				m_snowflake->getComponent<Transform>()->scale(0.03f, 0.03f);

				// Make it a Weapon
				m_snowflake->addComponent(new Weapon(m_snowflake));

				// change speed
				m_snowflake->getComponent<Weapon>()->mSpeed = 5000;

				// push into scene
				scene.push_back(m_snowflake);

				// set it to child of power ring
				scene[scene.size() - 2]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

				// reset power counter
				powerCounter = 0;
			}
		}
	}


	// ------------------ POWER RING COLLIDING WITH SQUARE ------------------------

	// if the square touches the power ring, then the power ring breaks
	// for every game object in the scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// if the game object is a power ring
		if (scene[i]->getComponent<Image>()->texture == barrier || scene[i]->getComponent<Image>()->texture == bulletRing ||
			scene[i]->getComponent<Image>()->texture == iceRing)
		{
			// for every game object in the scene
			for (unsigned int j = 0; j < scene.size(); j++)
			{
				// set limit to within scene
				if (i >= scene.size())
					i = scene.size() - 1;

				// if the current game object is a square
				if (scene[j]->getComponent<Image>()->texture == square)
				{
					// if the square's x position touches the power ring
					if (scene[j]->getComponent<Transform>()->getGlobalTransform().translation.x >
						(scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x - 60) &&
						scene[j]->getComponent<Transform>()->getGlobalTransform().translation.x <
						(scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x + 60))
					{
						// if the square's y position touches the power ring
						if (scene[j]->getComponent<Transform>()->getGlobalTransform().translation.y >
							(scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y - 60) &&
							scene[j]->getComponent<Transform>()->getGlobalTransform().translation.y <
							(scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y + 60))

							// if the square is active
							if (scene[j]->getComponent<Spawn>()->active)
							{
								// destroy the square
								scene[j]->getComponent<Transform>()->enabled = false;
								scene.erase(scene.begin() + j);
								for (unsigned int k = 0; k < scene.size(); k++)
								{
									// if the current game object is a power ring
									if (scene[k]->getComponent<Image>()->texture == barrier || scene[k]->getComponent<Image>()->texture == bulletRing ||
										scene[k]->getComponent<Image>()->texture == iceRing)
									{
										// destroy the barrier and remove as child
										scene[0]->getComponent<Transform>()->removeChild(scene[k]->getComponent<Transform>());
										scene.erase(scene.begin() + k);
										// if there is a bullet
										for (unsigned int l = 0; l < scene.size(); l++)
										{
											// erase bullet
											if (scene[l]->getComponent<Image>()->texture == bullet && scene[l]->getComponent<Weapon>()->active || 
												scene[l]->getComponent<Image>()->texture == snowflake && scene[l]->getComponent<Weapon>()->active)
												scene.erase(scene.begin() + l);
										}
									}
								}
							}
					}
				}
			}
		}
	}

	// ------------------ SHOOTING WEAPON ------------------------

	// Search scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// If right mouse button was clicked
		if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_RIGHT))
		{
			// if the current game object is a bullet
			if (scene[i]->getComponent<Image>()->texture == bullet || scene[i]->getComponent<Image>()->texture == snowflake)
			{
				// if the weapon is active
				if (scene[i]->getComponent<Weapon>()->active)
				{
					scene[i]->getComponent<Transform>()->getParent()->removeChild(scene[i]->getComponent<Transform>());	// remove bullet as child from power ring
					scene[i]->getComponent<Transform>()->getLocalTransform() = scene[0]->getComponent<Transform>()->getChild(0)->getLocalTransform();	// set bullet transform to bullet ring transform

					// set the bullets position to the red circle position
					scene[i]->getComponent<Transform>()->getLocalTransform().translation.x = scene[0]->getComponent<Transform>()->getLocalTransform().translation.x;
					scene[i]->getComponent<Transform>()->getLocalTransform().translation.y = scene[0]->getComponent<Transform>()->getLocalTransform().translation.y;

					// if snowflake, ensure the size is kept the same
					if (scene[i]->getComponent<Image>()->texture == snowflake)
						scene[i]->getComponent<Transform>()->scale(0.03f, 0.03f);

					// set weapon active to false
					scene[i]->getComponent<Weapon>()->active = false;
				}
			}
		}
	}

	// ------------------ WEAPON FALLS OFF SCREEN ------------------------

	// search scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// if current game object is a weapon
		if (scene[i]->getComponent<Image>()->texture == bullet && scene[i]->getComponent<Weapon>()->active == false ||
			scene[i]->getComponent<Image>()->texture == snowflake && scene[i]->getComponent<Weapon>()->active == false)
		{
			// if bullet moves off of the screen, move it to the left side at the same y axis it was at beforehand
			if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x > getWindowWidth() ||
				scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x < 0 ||
				scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y > getWindowHeight() ||
				scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y < 0)
			{
				// destroy the weapon
				scene.erase(scene.begin() + i);
			}
		}
	}

	// ------------------ BULLET COLLISIONS ------------------------

	// if the bullet touches a square or circle, then the spawn is destroyed
	// for every game object in the scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// if the game object is a square
		if (scene[i]->getComponent<Image>()->texture == square)
		{
			// for every game object in the scene
			for (unsigned int j = 0; j < scene.size(); j++)
			{
				// if the current game object is a bullet
				if (scene[j]->getComponent<Image>()->texture == bullet)
				{
					// if the weapon is inactive (not in power ring)
					if (scene[j]->getComponent<Weapon>()->active == false)
					{
						// if the square's x position touches the bullet
						if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x >
							(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.x - 20) &&
							scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x <
							(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.x + 20))
						{
							// if the square's y position touches the bullet
							if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y >
								(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.y - 20) &&
								scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y <
								(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.y + 20))
							{
								// destroy the square
								scene.erase(scene.begin() + i);
							}
						}
					}
				}
			}
		}
	}

	// ------------------ SNOWFLAKE COLLISIONS ------------------------

	// if the snowflake touches a square or circle, then the spawn is destroyed
	// for every game object in the scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// if the game object is a spawn
		if (scene[i]->getComponent<Image>()->texture == blueCircle || scene[i]->getComponent<Image>()->texture == square)
		{
			// for every game object in the scene
			for (unsigned int j = 0; j < scene.size(); j++)
			{
				// if the current game object is a snowflake
				if (scene[j]->getComponent<Image>()->texture == snowflake)
				{
					// if the snowflake is inactive (not in power ring)
					if (scene[j]->getComponent<Weapon>()->active == false)
					{
						// if the spawn's x position touches the snowflake
						if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x >
							(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.x - 20) &&
							scene[i]->getComponent<Transform>()->getGlobalTransform().translation.x <
							(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.x + 20))
						{
							// if the spawn's y position touches the snowflake
							if (scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y >
								(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.y - 20) &&
								scene[i]->getComponent<Transform>()->getGlobalTransform().translation.y <
								(scene[j]->getComponent<Transform>()->getGlobalTransform().translation.y + 20))
							{
								// disable the spawn (which will freeze them)
								scene[i]->getComponent<Spawn>()->enabled = false;
							}
						}
					}
				}
			}
		}
	}

	// ------------------ REPLENISHING WEAPONS ------------------------

	// for every game object in the scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		// if the player has a bullet ring or ice ring
		if (scene[i]->getComponent<Transform>()->childCount() == 1 && scene[i]->getComponent<Image>()->texture == bulletRing ||
			scene[i]->getComponent<Transform>()->childCount() == 1 && scene[i]->getComponent<Image>()->texture == iceRing)
		{
			// reload timer is set to 0
			scene[i]->getComponent<PowerUp>()->reloadTimer = 0;
		}
		// if the player has a bullet ring without a bullet
		else if (scene[i]->getComponent<Image>()->texture == bulletRing && scene[i]->getComponent<Transform>()->childCount() == 0)
		{
			// if the reload timer reaches 15
			if (scene[i]->getComponent<PowerUp>()->reloadTimer >= 15)
			{
				// Create the bullet game object
				GameObject* m_bullet = new GameObject;

				// set image and size
				m_bullet->addComponent(new Image(30, 30, bullet, m_bullet));

				// set to weapon
				m_bullet->addComponent(new Weapon(m_bullet));

				// push into scene
				scene.push_back(m_bullet);

				// set as child to power ring
				scene[i]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

				// reset reload timer
				scene[i]->getComponent<PowerUp>()->reloadTimer = 0;
			}
		}
		// if the player has a ice ring without a snowflake
		else if (scene[i]->getComponent<Image>()->texture == iceRing && scene[i]->getComponent<Transform>()->childCount() == 0)
		{
			// if the reload timer reaches 8
			if (scene[i]->getComponent<PowerUp>()->reloadTimer >= 8)
			{
				// Create the snowflake object
				GameObject* m_snowflake = new GameObject;

				// set image and size
				m_snowflake->addComponent(new Image(1115, 1275, snowflake, m_snowflake));

				// scale to fit within power ring
				m_snowflake->getComponent<Transform>()->scale(0.03f, 0.03f);

				// set to weapon
				m_snowflake->addComponent(new Weapon(m_snowflake));

				// set speed
				m_snowflake->getComponent<Weapon>()->mSpeed = 5000;

				// push into scene
				scene.push_back(m_snowflake);

				// set as child to power ring
				scene[i]->getComponent<Transform>()->addChild(scene[scene.size() - 1]->getComponent<Transform>());

				// reset reload timer
				scene[i]->getComponent<PowerUp>()->reloadTimer = 0;
			}
		}
	}

	// update every scene game object
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		scene[i]->update(deltaTime);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_SPACE))
	{
		scene.clear();
		scoreCount = 0;
		powerCounter = 0;
		num = -1;
		counter = 0;
		blueCount = 1;
		startup();
	}
}


void MathDemoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw everything in the scene
	for (unsigned int i = 0; i < scene.size(); i++)
	{
		scene[i]->draw(m_2dRenderer);
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press SPACE to restart", (getWindowWidth() - 390), 0);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Hold ENTER for instructions", (getWindowWidth() - 1200), 0);

	// output Score: in top left corner of screen
	m_2dRenderer->drawText(m_font, "Score: ", 0, (getWindowHeight() - 25));

	// output score number to the right of Score: 
	m_2dRenderer->drawText(m_font, score.c_str(), 110, (getWindowHeight() - 25));

	aie::Input* input = aie::Input::getInstance();

	// If enter key is down, display instructions
	if (input->isKeyDown(aie::INPUT_KEY_ENTER))
	{
		m_2dRenderer->drawText(m_font, "Left Click: Capture the Blue Circles within the Red Circle", (getWindowWidth() - 1500), (getWindowHeight() - 100));
		m_2dRenderer->drawText(m_font, "Right Click: Shoot Weapon", (getWindowWidth() - 1500), (getWindowHeight() - 150));
		m_2dRenderer->drawText(m_font, "Left Arrow/Q and Right Arrow/E: Rotate Bullet Ring (green)", (getWindowWidth() - 1500), (getWindowHeight() - 200));
		m_2dRenderer->drawText(m_font, "Capture circles and avoid squares!", (getWindowWidth() - 1500), (getWindowHeight() - 250));
		m_2dRenderer->drawText(m_font, "Bullets will destroy squares and Snowflakes will freeze anything they touch!", (getWindowWidth() - 1500), (getWindowHeight() - 300));
	}
	
	// when delay is over
	Player* player = scene[0]->getComponent<Player>();
	if (player != nullptr && player->deathCounter == 100)
	{
		// Display "Game Over" where the player died
		m_2dRenderer->drawText(m_font, "Game Over", (scene[0]->getComponent<Transform>()->getGlobalTransform().translation.x - scene[0]->getComponent<Image>()->width), 
			scene[0]->getComponent<Transform>()->getGlobalTransform().translation.y);
	}

	// done drawing sprites
	m_2dRenderer->end();
}

