#include "Player1.h"

// Constructor
Player1::Player1():
	texture(texture = new sf::Texture()), sprite(sprite = new sf::Sprite())
{
}

// Destructor
Player1::~Player1()
{
	delete texture;
	delete sprite;
}

// Set the texture for the paddle
void Player1::SetTexture()
{
	if (!texture->loadFromFile("C:/VisualStudio/Pong_SFML/Src/Paddle.png"))
	{
		std::cout << "Error: Texture did not load from file.\n";
	}
}

// Set the sprite for the paddle
void Player1::SetSprite()
{
	sprite->setTexture(*texture);
}

void Player1::SetPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

void Player1::SetScale(float x, float y)
{
	sprite->setScale(x, y);
}

void Player1::Render(sf::RenderWindow& window)
{
	window.draw(*sprite);
}

void Player1::MoveUp()
{
	sprite->move(0.0f, -speed);
}

void Player1::MoveDown()
{
	sprite->move(0.0f, speed);
}

void Player1::ConstrainPaddle(sf::RenderWindow& window, int width, int height)
{
	std::cout << sprite->getPosition().y << std::endl;
	if (sprite->getPosition().y < 0)
	{
		std::cout << "Collison\n";
		//speed = 0.0f;
		sprite->setPosition(100.0f, 1.0f);
	}
	
	if (sprite->getPosition().y > 1015)
	{
		std::cout << "Collison\n";
		//speed = 0.0f;
		sprite->setPosition(100.0f, 1015.0f);
	}
}