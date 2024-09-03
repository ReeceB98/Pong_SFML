#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"

class Paddle
{
public:

	// Constuctor & Destructor
	Paddle();
	~Paddle();

	// Set the texture and sprite of paddle
	void SetTexture();
	void SetSprite();
	void SetPosition(float x, float y);

	// Get paddle sprite to render to window
	sf::Sprite GetSprite();

private:

	// Texture and Sprite values for paddle
	sf::Texture* texture;
	sf::Sprite* sprite;
};

