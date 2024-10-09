#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

class Player2
{
public:

	// Constuctor & Destructor
	Player2();
	~Player2();

	void Initialize();

	// Set the texture and sprite of paddle
	void SetTexture();
	void SetSprite();
	void SetPosition(float x, float y);
	void SetScale(float x, float y);
	void SetSpeed(float currentSpeed);

	// Get paddle sprite to render to window
	void Render(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	void ConstrainPaddle();
	sf::FloatRect PaddleBounds();

	const sf::Vector2f GetPosition();
	const sf::Vector2f GetScale();

private:

	// Texture and Sprite values for paddle
	sf::Texture* texture;
	sf::Sprite* sprite;

	float speed = 1.0f;
	sf::Vector2f movement;

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};

