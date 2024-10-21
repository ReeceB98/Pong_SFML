#include "Player.h"

Player::Player() 
	: texture(texture = new sf::Texture()), sprite(sprite = new sf::Sprite()){}

Player::~Player()
{
	delete texture;
	delete sprite;
}

void Player::SetTexture(std::string texturePath)
{
	if (!texture->loadFromFile(texturePath))
	{
		std::cout << "Error: Could not load texture.\n";
	}
}

void Player::SetSprite()
{
	sprite->setTexture(*texture);
}

void Player::SetPosition(float x, float y)
{
	sprite->setPosition(x, y);
}

void Player::SetScale(float x, float y)
{
	sprite->setScale(x, y);
}

void Player::SetSpeed(float currentSpeed)
{
	speed = currentSpeed;
}

const sf::Vector2f Player::GetPosition()
{
	return sprite->getPosition();
}

const sf::Vector2f Player::GetScale()
{
	return sprite->getScale();
}

void Player::ConstrainPaddle(bool isPlayer1, bool isPlayer2)
{
	if (sprite->getPosition().y < 0.0f && isPlayer1)
	{
		sprite->setPosition(100.0f, 1.0f);
	}

	if (sprite->getPosition().y > 1015 && isPlayer1)
	{
		sprite->setPosition(100.0f, 1015.0f);
	}

	if (sprite->getPosition().y < 0.0f && isPlayer2)
	{
		sprite->setPosition(1800.0f, 1.0f);
	}

	if (sprite->getPosition().y > 1015 && isPlayer2)
	{
		sprite->setPosition(1800.0f, 1015.0f);
	}
}

sf::FloatRect Player::PaddleBounds()
{
	return sprite->getGlobalBounds();
}

void Player::MoveUp()
{
	sprite->move(0.0f, -speed);
}

void Player::MoveDown()
{
	sprite->move(0.0f, speed);
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(*sprite);
}
