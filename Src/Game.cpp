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

		playerOne.SetTexture("C:/VisualStudio/Pong_SFML/Src/Paddle.png");
		playerOne.SetSprite();
		playerOne.SetPosition(100.0f, 500.0f);
		playerOne.SetScale(6.0f, 6.0f);

		playerTwo.SetTexture("C:/VisualStudio/Pong_SFML/Src/Paddle.png");
		playerTwo.SetSprite();
		playerTwo.SetPosition(1800.0f, 500.0f);
		playerTwo.SetScale(6.0f, 6.0f);
	
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
		playerOne.ConstrainPaddle(true, false);
		playerTwo.ConstrainPaddle(false, true);

		// Ball movements updated each frame
		ball.Move(*window);

		// Checks collision between player 1 and ball
		if (ball.BallBounds().intersects(playerOne.PaddleBounds()))
		{
			// Find the centers of player 1 paddle and ball
			float paddleCenter = playerOne.GetPosition().y + playerOne.GetScale().y / 2.0f;
			float ballCenter = ball.GetPosition().y + ball.GetScale().y;

			// Find the difference of the centers and normalize
			float difference = ballCenter - paddleCenter;
			float normalizedDifference = difference / (playerOne.GetScale().x / 2.0f);

			// if the ball hits the top of paddle, ball will go upwards
			if (normalizedDifference >= -7.0f && normalizedDifference < 16.0f)
			{
				ball.SetVelocity(1.0f, ball.SetRandomBallPos(-randMin, -randMax));
			}
			// if the ball hits the middle of paddle ball
			else if (normalizedDifference >= 16.0f && normalizedDifference < 41.0f)
			{
				ball.SetVelocity(1.0f, ball.SetRandomBallPos(-randMid, randMid));
			}
			// if the ball hits the bottom of the paddle, ball goes downwards
			else if (normalizedDifference >= 41.0f && normalizedDifference <= 64)
			{
				ball.SetVelocity(1.0f, ball.SetRandomBallPos(randMax, randMin));
			}
		}

		// Checks collision between player 2 and ball
		if (ball.BallBounds().intersects(playerTwo.PaddleBounds()))
		{
			// Find the centers of player 2 paddle and ball
			float paddleCenter = playerTwo.GetPosition().y + playerTwo.GetScale().y / 2.0f;
			float ballCenter = ball.GetPosition().y + ball.GetScale().y;

			// Find the difference of the centers and normalize
			float difference = ballCenter - paddleCenter;
			float normalizedDifference = difference / (playerTwo.GetScale().x / 2.0f);

			// if the ball hits the top of paddle, ball will go upwards
			if (normalizedDifference >= -7.0f && normalizedDifference < 16.0f)
			{
				ball.SetVelocity(-1.0f, ball.SetRandomBallPos(-randMin, -randMax));
			}
			// if the ball hits the middle of paddle ball
			else if (normalizedDifference >= 16.0f && normalizedDifference < 41.0f)
			{
				ball.SetVelocity(-1.0f, ball.SetRandomBallPos(-randMid, randMid));
			}
			// if the ball hits the bottom of the paddle, ball goes downwards
			else if (normalizedDifference >= 41.0f && normalizedDifference <= 64)
			{
				ball.SetVelocity(-1.0f, ball.SetRandomBallPos(randMax, randMin));
			}
		}

		// Updates the score based on which player has scored
		if (ball.GetPosition().x <= 0.0f)
		{
			player2Score.SetScore();
			ball.SetBallVelocity(0.0f, 0.0f);
			ball.SetPosition(950.0f, 500.0f);
			player2Scored = true;
			playerOne.SetPosition(100.0f, 500.0f);
			playerTwo.SetPosition(1800.0f, 500.0f);
			clock.restart();
		}
		else if (ball.GetPosition().x >= 1920)
		{
			player1Score.SetScore();
			ball.SetBallVelocity(0.0f, 0.0f);
			ball.SetPosition(950.0f, 500.0f);
			player1Scored = true;
			playerOne.SetPosition(100.0f, 500.0f);
			playerTwo.SetPosition(1800.0f, 500.0f);
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
			playerOne.SetPosition(100.0f, 500.0f);
			playerOne.SetSpeed(0.0f);
			playerTwo.SetPosition(1800.0f, 500.0f);
			playerTwo.SetSpeed(0.0f);

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
					playerOne.SetSpeed(1.0f);
					playerTwo.SetSpeed(1.0f);
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
			playerOne.SetPosition(100.0f, 500.0f);
			playerOne.SetSpeed(0.0f);
			playerTwo.SetPosition(1800.0f, 500.0f);
			playerTwo.SetSpeed(0.0f);

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
					playerOne.SetSpeed(1.0f);
					playerTwo.SetSpeed(1.0f);
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
			playerOne.MoveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			playerOne.MoveDown();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerTwo.MoveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerTwo.MoveDown();
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
		playerOne.Render(*window);
		playerTwo.Render(*window);
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
