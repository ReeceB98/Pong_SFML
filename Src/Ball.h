#pragma once

#include <iostream>
#include "Player1.h"

#include "SFML/Graphics.hpp"

class Ball
{
public:
	
	// Constructor & Destructor
	Ball();
	~Ball();

	// Initialize, Move and Render the ball sprite
	void Initialize();
	void Move(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

private:

	// Property functions to define the ball sprite
	void SetTexture();
	void SetSprite();
	void SetPosition(float x, float y);
	void SetInitVelocity(float x, float y);

	// Variables
	sf::Texture* texture;
	sf::Sprite* sprite;

	sf::Vector2f ballVelocity;
	sf::Vector2f ballPosition;
};

