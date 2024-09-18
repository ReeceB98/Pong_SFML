#include "Game.h"

// Constructor
Game::Game() :
	window(window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML works!")), event(event)
{
}

// Destructor
Game::~Game()
{
	delete window;
}

// Opens the window and runs the game
void Game::Run()
{
	Initialize();

	while (window->isOpen())
	{
		Update();
		HandleInputs();
		Render();
	}

}

// Intialize any data needed for game objects
void Game::Initialize()
{
	player1.SetTexture();
	player1.SetSprite();
	player1.SetPosition(100.0f, 500.0f);
	player1.SetScale(2.0f, 2.0f);

	player2.SetTexture();
	player2.SetSprite();
	player2.SetPosition(1800.0f, 500.0f);
	player2.SetScale(2.0f, 2.0f);

	ball.Initialize();
}

// Updates anything in the window by frame
void Game::Update()
{
	player1.ConstrainPaddle();
	player2.ConstrainPaddle();
	ball.Move(*window);
}

// Handle game inputs 
void Game::HandleInputs()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player1.MoveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player1.MoveDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player2.MoveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player2.MoveDown();
	}
}

// Render any sprites to the window screen
void Game::Render()
{
	window->clear();
	// Render between the lines
	player1.Render(*window);
	player2.Render(*window);
	ball.Render(*window);
	// Render between the lines
	window->display();
}
