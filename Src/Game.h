#pragma once

#include "SFML/Graphics.hpp"

class Game
{
public:

	Game();
    ~Game();
	void Run();

private:

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow *mWindow;

    static const sf::Time TimePerFrame;
};

