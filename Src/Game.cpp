#include "Game.h"

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> negativeDis(-0.8f, -0.2f);
std::uniform_real_distribution<> positiveDis(0.2f, 0.8f);
std::uniform_real_distribution<> middleDis(-0.1f, 0.1f);

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
		title.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
		title.SetText("Pong");
		title.SetCharacterSize(160);
		title.SetPosition(600.0f, 100.0f);

		playButton.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
		playButton.SetText("Play");
		playButton.SetCharacterSize(120);
		playButton.SetPosition(725.0f, 400.0f);

		quitButton.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
		quitButton.SetText("Quit");
		quitButton.SetCharacterSize(120);
		quitButton.SetPosition(725.0f, 700.0f);

		playAgainButton.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
		playAgainButton.SetText("Play Again");
		playAgainButton.SetCharacterSize(120);
		playAgainButton.SetPosition(400.0f, 700.0f);
		playAgainButton.SetTextColour(sf::Color::Transparent);

		playerOneWins.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
		playerOneWins.SetText("Player 1 Wins");
		playerOneWins.SetCharacterSize(120);
		playerOneWins.SetPosition(300.0f, 200.0f);
		playerOneWins.SetTextColour(sf::Color::Transparent);

		playerTwoWins.SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
		playerTwoWins.SetText("Player 2 Wins");
		playerTwoWins.SetCharacterSize(120);
		playerTwoWins.SetPosition(300.0f, 200.0f);
		playerTwoWins.SetTextColour(sf::Color::Transparent);
	
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
	float negativeRandNum = negativeDis(gen);
	float positiveRandNum = positiveDis(gen);
	float middleRandNum = middleDis(gen);

	if (currentScene == MENU)
	{
		sf::Vector2i localPos = sf::Mouse::getPosition(*window);

		if (playButton.GetTextBounds().contains(localPos.x, localPos.y))
		{
			playButton.SetTextColour(sf::Color::Yellow);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				currentScene = GAMEPLAY;
				startTimer = true;
			}
		}
		else
		{
			playButton.SetTextColour(sf::Color::White);
		}

		if (quitButton.GetTextBounds().contains(localPos.x, localPos.y))
		{
			quitButton.SetTextColour(sf::Color::Yellow);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window->close();
			}
		}
		else
		{
			quitButton.SetTextColour(sf::Color::White);
		}
	}

	if (currentScene == GAMEPLAY)
	{

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
			if (normalizedDifference >= -7.0f && normalizedDifference < 16.0f)
			{
				ball.SetVelocity(1.0f, negativeRandNum);
			}
			// if the ball hits the middle of paddle ball
			else if (normalizedDifference >= 16.0f && normalizedDifference < 41.0f)
			{
				ball.SetVelocity(1.0f, middleRandNum);
			}
			// if the ball hits the bottom of the paddle, ball goes downwards
			else if (normalizedDifference >= 41.0f && normalizedDifference <= 64)
			{
				ball.SetVelocity(1.0f, positiveRandNum);
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
			if (normalizedDifference >= -7.0f && normalizedDifference < 16.0f)
			{
				ball.SetVelocity(-1.0f, negativeRandNum);
			}
			// if the ball hits the middle of paddle ball
			else if (normalizedDifference >= 16.0f && normalizedDifference < 41.0f)
			{
				ball.SetVelocity(-1.0f, middleRandNum);
			}
			// if the ball hits the bottom of the paddle, ball goes downwards
			else if (normalizedDifference >= 41.0f && normalizedDifference <= 64)
			{
				ball.SetVelocity(-1.0f, positiveRandNum);
			}
		}

		// Updates the score based on which player has scored
		if (ball.GetPosition().x <= 0.0f)
		{
			player2Score.SetScore();
			ball.SetBallVelocity(0.0f, 0.0f);
			ball.SetPosition(950.0f, 500.0f);
			player2Scored = true;
			player1.SetPosition(100.0f, 500.0f);
			player2.SetPosition(1800.0f, 500.0f);
			clock.restart();
		}
		else if (ball.GetPosition().x >= 1920)
		{
			player1Score.SetScore();
			ball.SetBallVelocity(0.0f, 0.0f);
			ball.SetPosition(950.0f, 500.0f);
			player1Scored = true;
			player1.SetPosition(100.0f, 500.0f);
			player2.SetPosition(1800.0f, 500.0f);
			clock.restart();
		}

		if (player1Scored)
		{
			time = clock.getElapsedTime();

			if (time.asSeconds() >= 1.0f)
			{
				player1Scored = false;
				ball.SetBallVelocity(-1.0f, 0.0f);
			}
		}
		else if (player2Scored)
		{
			time = clock.getElapsedTime();

			if (time.asSeconds() >= 1.0f)
			{
				player2Scored = false;
				ball.SetBallVelocity(1.0f, 0.0f);
			}
		}

		if (player1Score.GetScore() == 7)
		{
			playerOneWins.SetTextColour(sf::Color::White);
			playAgainButton.SetTextColour(sf::Color::White);

			ball.SetVelocity(0.0f, 0.0f);
			player1.SetPosition(100.0f, 500.0f);
			player1.SetSpeed(0.0f);
			player2.SetPosition(1800.0f, 500.0f);
			player2.SetSpeed(0.0f);

			sf::Vector2i localPos = sf::Mouse::getPosition(*window);

			if (playAgainButton.GetTextBounds().contains(localPos.x, localPos.y))
			{
				playAgainButton.SetTextColour(sf::Color::Yellow);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					startTimer = true;
					player1Score.SetText("0");
					player2Score.SetText("0");
					playerOneWins.SetTextColour(sf::Color::Transparent);
					playAgainButton.SetTextColour(sf::Color::Transparent);
					player1Score.ResetScore();
					player2Score.ResetScore();
					ball.SetVelocity(-1.0f, 0.0f);
					player1.SetSpeed(1.0f);
					player2.SetSpeed(1.0f);
				}
			}
			else
			{
				playAgainButton.SetTextColour(sf::Color::White);
			}
		}

		if (player2Score.GetScore() == 7)
		{
			playerTwoWins.SetTextColour(sf::Color::White);
			playAgainButton.SetTextColour(sf::Color::White);

			ball.SetVelocity(0.0f, 0.0f);
			player1.SetPosition(100.0f, 500.0f);
			player1.SetSpeed(0.0f);
			player2.SetPosition(1800.0f, 500.0f);
			player2.SetSpeed(0.0f);

			sf::Vector2i localPos = sf::Mouse::getPosition(*window);

			if (playAgainButton.GetTextBounds().contains(localPos.x, localPos.y))
			{
				playAgainButton.SetTextColour(sf::Color::Yellow);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					startTimer = true;
					player1Score.SetText("0");
					player2Score.SetText("0");
					playerTwoWins.SetTextColour(sf::Color::Transparent);
					playAgainButton.SetTextColour(sf::Color::Transparent);
					player1Score.ResetScore();
					player2Score.ResetScore();
					ball.SetVelocity(-1.0f, 0.0f);
					player1.SetSpeed(1.0f);
					player2.SetSpeed(1.0f);
				}
			}
			else
			{
				playAgainButton.SetTextColour(sf::Color::White);
			}
		}
	}
}

// Handle game inputs 
void Game::HandleInputs()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	if (currentScene == GAMEPLAY)
	{

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
}

// Render any sprites to the window screen
void Game::Render()
{
	window->clear();
	// Render between the lines
	if (currentScene == MENU)
	{
		title.Render(*window);
		playButton.Render(*window);
		quitButton.Render(*window);
	}

	if (currentScene == GAMEPLAY)
	{
		player1.Render(*window);
		player2.Render(*window);
		ball.Render(*window);
		player1Score.Render(*window);
		player2Score.Render(*window);
		playerOneWins.Render(*window);
		playerTwoWins.Render(*window);
		playAgainButton.Render(*window);
	}
	// Render between the lines
	window->display();
}
