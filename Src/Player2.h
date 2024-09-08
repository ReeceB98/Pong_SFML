#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

class Player2
{
public:

	// Constuctor & Destructor
	Player2();
	~Player2();

	// Set the texture and sprite of paddle
	void SetTexture();
	void SetSprite();
	void SetPosition(float x, float y);
	void SetScale(float x, float y);

	// Get paddle sprite to render to window
	void Render(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

private:

	// Texture and Sprite values for paddle
	sf::Texture* texture;
	sf::Sprite* sprite;

	float speed = 0.4f;
	sf::Vector2f movement;

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};

