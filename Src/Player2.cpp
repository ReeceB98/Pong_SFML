#include "Player2.h"

// Constructor
Player2::Player2() :
	texture(texture = new sf::Texture()), sprite(sprite = new sf::Sprite())
{
}

// Destructor
Player2::~Player2()
{
	delete texture;
	delete sprite;
}

// Set the texture for the paddle
void Player2::SetTexture()
{
	if (!texture->loadFromFile("C:/VisualStudio/Pong_SFML/Src/Paddle.png"))
	{
		std::cout << "Error: Texture did not load from file.\n";
	}
}

// Set the sprite for the paddle
void Player2::SetSprite()
{
	sprite->setTexture(*texture);
}

void Player2::SetPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

void Player2::SetScale(float x, float y)
{
	sprite->setScale(x, y);
}

void Player2::Render(sf::RenderWindow& window)
{
	window.draw(*sprite);
}

void Player2::MoveUp()
{
	sprite->move(0.0f, -speed);
}

void Player2::MoveDown()
{
	sprite->move(0.0f, speed);
}