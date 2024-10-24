#pragma once
#include <random>

#include "SFML/Graphics.hpp"

#include "Player.h"
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
	Player playerOne;
	Player playerTwo;

	// Ball
	Ball ball;
	// Random ball direction values
	float randMin = 0.8f;
	float randMax = 0.2f;
	float randMid = 0.1f;

	// Score
	Score player1Score;
	Score player2Score;

	// Game scene selection
	int currentScene = 0;
	enum sceneName {MENU, GAMEPLAY, ENDSCREEN};

	// Used to help with delay gameplay
	sf::Clock clock;
	sf::Time time;

	// A check to see which player has scored
	bool player1Scored = false;
	bool player2Scored = false;

	// All the text that is displayed in the game
	Menu title;
	Menu playButton;
	Menu quitButton;
	Menu playerOneWins;
	Menu playerTwoWins;
	Menu playAgainButton;

	// Trigger the timer after the game has paused for limited time
	bool startTimer = false;

	// Screen width variables
	float minScreenWidth = 0.0f;
	float maxScreenWidth = 1920.0f;
};

