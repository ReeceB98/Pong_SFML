#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Menu
{

public:

	// Constructor & Destructor
	Menu();
	~Menu();

	// Getters
	sf::FloatRect GetTextBounds();

	// Setters
	void SetFont(std::string path);
	void SetText(std::string phrase);
	void SetPosition(float x, float y);
	void SetCharacterSize(int size);
	void SetTextColour(sf::Color colour);

	// Render menu text(s) to screen
	void Render(sf::RenderWindow& window);

private:

	sf::Font* font;
	sf::Text* text;
};

