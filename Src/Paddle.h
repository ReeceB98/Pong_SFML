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
	void SetScale(float x, float y);

	// Get paddle sprite to render to window
	sf::Sprite GetSprite();
	void Render(sf::RenderWindow& window);
	void Move(float dt);

	float SetSpeed(float currentSpeed);

	void ProcessEvents(sf::Keyboard::Key key, bool checkPressed);

private:

	// Texture and Sprite values for paddle
	sf::Texture* texture;
	sf::Sprite* sprite;

	float speed = 0.0f;
	sf::Vector2f movement;

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};

