#include "Ball.h"

// Constructor
Ball::Ball() : texture(texture = new sf::Texture()), sprite(sprite = new sf::Sprite()), ballVelocity(ballVelocity), ballPosition(ballPosition)
{
}

// Destructor
Ball::~Ball()
{
	delete texture;
	delete sprite;
}

// Initialize all properties to define the ball sprite
void Ball::Initialize()
{
	SetTexture();
	SetSprite();
	SetPosition(950, 500);
	SetInitVelocity(0.5f, -0.5f);
}

// Sets the texture for the ball sprite from file
void Ball::SetTexture()
{
	if (!texture->loadFromFile("C:/VisualStudio/Pong_SFML/Src/Ball.png"))
	{
		std::cout << "Texture did not load from file\n";
	}
}

// Sprite is set up to be a ball
void Ball::SetSprite()
{
	sprite->setTexture(*texture);
}

// Initial position of ball at start up
void Ball::SetPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

// Initial velocity at start up
void Ball::SetInitVelocity(float x, float y)
{
	ballVelocity.x = x;
	ballVelocity.y = y;
}

// Moves the ball across the screen
void Ball::Move(sf::RenderWindow& window)
{
	// Get the balls position each frame
	ballPosition = sprite->getPosition();

	// Detects if the ball hit the left or right side of the wall
	// Will bounce if collision happens
	if (ballPosition.x <= 0.0f)
	{
		ballVelocity.x = -ballVelocity.x;
	}
	else if (ballPosition.x >= 1920.0f)
	{
		ballVelocity.x = -ballVelocity.x;
	}

	// Detects if the ball hit the top or bottom of the wall
	// Will bounce if collision happens
	if (ballPosition.y <= 0.0f)
	{
		ballVelocity.y = -ballVelocity.y;
	}
	else if (ballPosition.y >= 1080.0f)
	{
		ballVelocity.y = -ballVelocity.y;
	}

	// Move the ball sprite each frame
	sprite->move(ballVelocity);
}

// Renders the sprite to be seen on the window
void Ball::Render(sf::RenderWindow& window)
{
	window.draw(*sprite);
}
