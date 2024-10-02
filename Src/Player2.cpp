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

void Player2::Initialize()
{
	SetTexture();
	SetSprite();
	SetPosition(1800.0f, 500.0f);
	SetScale(4.0f, 4.0f);
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

void Player2::ConstrainPaddle()
{
	//std::cout << sprite->getPosition().y << std::endl;
	if (sprite->getPosition().y < 0)
	{
		sprite->setPosition(1800.0f, 1.0f);
	}

	if (sprite->getPosition().y > 1015)
	{
		sprite->setPosition(1800.0f, 1015.0f);
	}
}

sf::FloatRect Player2::PaddleBounds()
{
	return sprite->getGlobalBounds();
}

const sf::Vector2f Player2::GetPosition()
{
	return sprite->getPosition();
}

const sf::Vector2f Player2::GetScale()
{
	return sprite->getScale();
}