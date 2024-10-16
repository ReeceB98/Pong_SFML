#pragma once
#include <random>

#include "SFML/Graphics.hpp"

#include "Player1.h"
#include "Player2.h"
#include "Ball.h"
#include "Score.h"
#include "Menu.h"

class Game
{
public:

	// Constructor & Destructor
	Game();
	~Game();

	// Opens the window and runs the game
	void Run();

private:

	bool test = false;
	// Renders 2d objects to the screen
	sf::RenderWindow *window;
	unsigned int windowWidth = 1920;
	unsigned int windowHeight = 1080;

	// Used to set up inputs
	sf::Event event;

	// Initialize, Updates, handles game inputs and renders sprites to the screen
	void Initialize();
	void Update();
	void HandleInputs();
	void Render();

	// Paddles
	Player1 player1;
	Player2 player2;

	// Ball
	Ball ball;

	// Score
	Score player1Score;
	Score player2Score;

	int currentScene = 0;
	enum sceneName {MENU, GAMEPLAY, ENDSCREEN};

	sf::Clock clock;
	sf::Time time;

	bool player1Scored = false;
	bool player2Scored = false;

	Menu title;
	Menu playButton;
	Menu quitButton;
	Menu playerOneWins;
	Menu playerTwoWins;
	Menu playAgainButton;

	bool startTimer = false;
};

