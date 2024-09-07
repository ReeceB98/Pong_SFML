#include "Paddle.h"

// Constructor
Paddle::Paddle():
	texture(texture = new sf::Texture()), sprite(sprite = new sf::Sprite())
{
}

// Destructor
Paddle::~Paddle()
{
	delete texture;
	delete sprite;
}

// Set the texture for the paddle
void Paddle::SetTexture()
{
	if (!texture->loadFromFile("C:/VisualStudio/Pong_SFML/Src/Paddle.png"))
	{
		std::cout << "Error: Texture did not load from file.\n";
	}
}

// Set the sprite for the paddle
void Paddle::SetSprite()
{
	sprite->setTexture(*texture);
}

void Paddle::SetPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

void Paddle::SetScale(float x, float y)
{
	sprite->setScale(x, y);
}

sf::Sprite Paddle::GetSprite()
{
	return *sprite;
}

void Paddle::Render(sf::RenderWindow& window)
{
	window.draw(*sprite);
}

void Paddle::Move(float dt)
{
	if (up)
	{
		movement.y = -100.0f;
	}
	else if (down)
	{
		movement.y = 100.0f;
	}

	sprite->move(movement * dt);
}

float Paddle::SetSpeed(float currentSpeed)
{
	return speed;
}

void Paddle::ProcessEvents(sf::Keyboard::Key key, bool checkPressed)
{
	if (checkPressed)
	{
		if (key == sf::Keyboard::W)
		{
			up = true;
		}
		else if (key == sf::Keyboard::S)
		{
			down = true;
		}
	}
	else if (!checkPressed)
	{
		up = false;
		down = false;
	}
}