#pragma once

#include "SFML/Graphics.hpp"

#include "Player1.h"
#include "Player2.h"

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
	//Paddle playerOnePaddle;
	Player1 player1;
	Player2 player2;
};

