#include "Game.h"

// Constructor
Game::Game() :
	window(window = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML works!")), event(event)
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
	while (window->isOpen())
	{
		Initialize();
		Update();
		HandleInputs();
		Render();
	}
}

// Intialize any data needed for game objects
void Game::Initialize()
{
	//playerOnePaddle.SetTexture();
	//playerOnePaddle.SetSprite();
	//playerOnePaddle.SetPosition(100.0f, 100.0f);

	player1.SetTexture();
	player1.SetSprite();
	player1.SetPosition(100.0f, 100.0f);

	player2.SetTexture();
	player2.SetSprite();
	player2.SetPosition(400.0f, 400.0f);
}

// Updates anything in the window by frame
void Game::Update()
{
	
}

// Handle game inputs 
void Game::HandleInputs()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

// Render any sprites to the window screen
void Game::Render()
{
	window->clear();
	// Render between the lines
	window->draw(player1.GetSprite());
	window->draw(player2.GetSprite());
	// Render between the lines
	window->display();
}
