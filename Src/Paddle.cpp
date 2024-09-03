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

sf::Sprite Paddle::GetSprite()
{
	return *sprite;
}