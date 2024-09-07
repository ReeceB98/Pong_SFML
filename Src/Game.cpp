#include "Game.h"
float speed = 0;
//sf::Clock clock;
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
	playerOne.SetTexture();
	playerOne.SetSprite();
	playerOne.SetPosition(100.0f, 100.0f);

	playerTwo.SetTexture();
	playerTwo.SetSprite();
	playerTwo.SetPosition(400.0f, 400.0f);
}

// Updates anything in the window by frame
void Game::Update()
{
	float deltaTime = clock.restart().asSeconds();
	//player1.SetMove();
	//playerOne.GetSprite().move(0.0f, speed);
	//playerOne.Move(0.0f, playerOne.SetSpeed(-1.0f));
	playerOne.Move(deltaTime);
}

// Handle game inputs 
void Game::HandleInputs()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
		{
			playerOne.ProcessEvents(event.key.code, true);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			playerOne.ProcessEvents(event.key.code, false);
		}
	}
}

// Render any sprites to the window screen
void Game::Render()
{
	window->clear();
	// Render between the lines
	//window->draw(playerOne.GetSprite());
	playerOne.Render(*window);
	playerTwo.Render(*window);
	// Render between the lines
	window->display();
}
