#include "Game.h"

// Constructor
Game::Game() :
	window(window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML works!")), event(event){}

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
	player1.Initialize();
	player2.Initialize();
	ball.Initialize();

	player1Score.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
	player1Score.SetText("0");
	player1Score.SetPosition(700.0f, 0.0f);
	player1Score.SetCharacterSize(120.0f);

	player2Score.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
	player2Score.SetText("0");
	player2Score.SetPosition(1100.0f, 0.0f);
	player2Score.SetCharacterSize(120.0f);
}

// Updates anything in the window by frame
void Game::Update()
{
	if (currentScene == GAMEPLAY)
	{

		//time = clock.getElapsedTime();

		// Stops both paddles from going off the window screen
		player1.ConstrainPaddle();
		player2.ConstrainPaddle();

		// Ball movements updated each frame
		ball.Move(*window);

		// Checks collision between player 1 and ball
		if (ball.BallBounds().intersects(player1.PaddleBounds()))
		{
			// Find the centers of player 1 paddle and ball
			float paddleCenter = player1.GetPosition().y + player1.GetScale().y / 2.0f;
			float ballCenter = ball.GetPosition().y + ball.GetScale().y;

			// Find the difference of the centers and normalize
			float difference = ballCenter - paddleCenter;
			float normalizedDifference = difference / (player1.GetScale().x / 2.0f);

			// if the ball hits the top of paddle, ball will go upwards
			if (normalizedDifference >= -7.5f && normalizedDifference < 24.5)
			{
				ball.SetVelocity(1.0f, -0.4f);
			}
			// if the ball hits the middle of paddle ball
			else if (normalizedDifference >= 24.5 && normalizedDifference < 34.5)
			{
				ball.SetVelocity(1.0f, -0.1f);
			}
			// if the ball hits the bottom of the paddle, ball goes downwards
			else if (normalizedDifference >= 34.5 && normalizedDifference <= 63)
			{
				ball.SetVelocity(1.0f, 0.4f);
			}
		}

		// Checks collision between player 2 and ball
		if (ball.BallBounds().intersects(player2.PaddleBounds()))
		{
			// Find the centers of player 2 paddle and ball
			float paddleCenter = player2.GetPosition().y + player2.GetScale().y / 2.0f;
			float ballCenter = ball.GetPosition().y + ball.GetScale().y;

			// Find the difference of the centers and normalize
			float difference = ballCenter - paddleCenter;
			float normalizedDifference = difference / (player2.GetScale().x / 2.0f);

			// if the ball hits the top of paddle, ball will go upwards
			if (normalizedDifference >= -7.5f && normalizedDifference < 24.5)
			{
				ball.SetVelocity(-1.0f, -0.4f);
			}
			// if the ball hits the middle of paddle ball
			else if (normalizedDifference >= 24.5 && normalizedDifference < 34.5)
			{
				ball.SetVelocity(-1.0f, -0.1f);
			}
			// if the ball hits the bottom of the paddle, ball goes downwards
			else if (normalizedDifference >= 34.5 && normalizedDifference <= 63)
			{
				ball.SetVelocity(-1.0f, 0.4f);
			}

		}

		// Updates the score based on which player has scored
		if (ball.GetPosition().x <= 0.0f)
		{
			player2Score.SetScore();
			ball.SetBallVelocity(0.0f, 0.0f);
			ball.SetPosition(950.0f, 500.0f);
			player2Scored = true;
			clock.restart();
		}
		else if (ball.GetPosition().x >= 1920)
		{
			player1Score.SetScore();
			ball.SetBallVelocity(0.0f, 0.0f);
			ball.SetPosition(950.0f, 500.0f);
			player1Scored = true;
			clock.restart();
		}

		if (player1Scored)
		{
			time = clock.getElapsedTime();

			if (time.asSeconds() > 3.0f)
			{
				player1Scored = false;
				ball.SetBallVelocity(-1.0f, 0.0f);
			}
		}
		else if (player2Scored)
		{
			time = clock.getElapsedTime();

			if (time.asSeconds() >= 3.0f)
			{
				player2Scored = false;
				ball.SetBallVelocity(1.0f, 0.0f);
			}
		}
	}
}

// Handle game inputs 
void Game::HandleInputs()
{
	if (currentScene == GAMEPLAY)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		currentScene = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		currentScene = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		currentScene = 2;
	}
}

// Render any sprites to the window screen
void Game::Render()
{
	window->clear();
	// Render between the lines
	if (currentScene == GAMEPLAY)
	{
		player1.Render(*window);
		player2.Render(*window);
		ball.Render(*window);
		//score.Render(*window);
		player1Score.Render(*window);
		player2Score.Render(*window);
	}
	// Render between the lines
	window->display();
}
