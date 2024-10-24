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

void Ball::StartBall(sf::Time time, sf::Clock clock, bool startTime)
{
	if (isStarting)
	{
		time = clock.getElapsedTime();
		std::cout << time.asSeconds() << std::endl;

		if (time.asSeconds() >= 5.0f)
		{
			SetBallVelocity(-1.0f, 0.0f);
		}

		isStarting = false;
	}
}

float Ball::SetRandomBallPos(float min, float max)
{
	// Generates a random number seed
	std::random_device rd;
	std::mt19937 gen(rd());

	// Set the min & max number for number generator seed
	std::uniform_real_distribution<> dis(min, max);

	// return random float number to set the ball direction
	float randNum = dis(gen);
	return randNum;
}

void Ball::SetScale(float x, float y)
{
	sprite->setScale(x, y);
}

// Initial velocity at start up
void Ball::SetInitVelocity(float x, float y)
{
	ballVelocity.x = x * speed;
	ballVelocity.y = y * speed;
}

// Moves the ball across the screen
void Ball::Move(sf::RenderWindow& window)
{
	// Get the balls position each frame
	ballPosition = sprite->getPosition();

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

sf::FloatRect Ball::BallBounds()
{
	return sprite->getGlobalBounds();
}

void Ball::SetBallVelocity(float x, float y)
{
	ballVelocity.x = x;
	ballVelocity.y = y;
}

const sf::Vector2f Ball::GetPosition()
{
	return sprite->getPosition();
}

const sf::Vector2f Ball::GetScale()
{
	return sprite->getScale();
}

void Ball::GetBallVelocityX(float normDiff)
{
	ballVelocity.x = normDiff * 0.01f;
}

void Ball::GetBallVelocityY()
{
	ballVelocity.y = -ballVelocity.y;
}

sf::Vector2f Ball::GetBallVelocity()
{
	return ballVelocity;
}

void Ball::SetVelocity(float x, float y)
{
	ballVelocity.x = x;
	ballVelocity.y = y;
}
