#pragma once

#include "SFML/Graphics.hpp"

#include "Paddle.h"

class Game
{
public:

	// Constructor & Destructor
	Game();
	~Game();

	// Opens the window and runs the game
	void Run();

private:

	// Renders 2d objects to the screen
	sf::RenderWindow *window;

	// Used to set up inputs
	sf::Event event;

	// Initialize, Updates, handles game inputs and renders sprites to the screen
	void Initialize();
	void Update();
	void HandleInputs();
	void Render();

	// Paddles
	Paddle playerOne;
	Paddle playerTwo;

	sf::Clock clock;
};

