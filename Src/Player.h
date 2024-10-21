#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
public:
	// Constructor & Destructor
	Player();
	~Player();

	// Setters
	void SetTexture(std::string texturePath);
	void SetSprite();
	void SetPosition(float x, float y);
	void SetScale(float x, float y);
	void SetSpeed(float currentSpeed);

	// Getters
	const sf::Vector2f GetPosition();
	const sf::Vector2f GetScale();

	void ConstrainPaddle(bool isPlayerOne, bool isPlayer2);
	sf::FloatRect PaddleBounds();
	void MoveUp();
	void MoveDown();

	// Render the sprite to the screen
	void Render(sf::RenderWindow& window);

private:

	sf::Texture* texture;
	sf::Sprite* sprite;

	float speed = 1.0f;
};

