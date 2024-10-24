#pragma once

#include <iostream>
#include <random>
#include "Score.h"
#include "SFML/Graphics.hpp"

class Ball
{
public:
	
	// Constructor & Destructor
	Ball();
	~Ball();

	void StartBall(sf::Time time, sf::Clock clock, bool startTime);
	void Move(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);
	sf::FloatRect BallBounds();
	void SetBallVelocity(float x, float y);

	// Getters
	const sf::Vector2f GetPosition();
	const sf::Vector2f GetScale();
	void GetBallVelocityX(float normDiff);
	void GetBallVelocityY();
	sf::Vector2f GetBallVelocity();

	// Setters
	void SetVelocity(float x, float y);
	void SetPosition(float x, float y);
	float SetRandomBallPos(float min, float max);
	void SetTexture();
	void SetSprite();
	void SetScale(float x, float y);
	void SetInitVelocity(float x, float y);

private:

	// Variables
	sf::Texture* texture;
	sf::Sprite* sprite;

	sf::Vector2f ballVelocity;
	sf::Vector2f ballPosition;
	float speed = 1.0f;

	bool isStarting = true;
};

