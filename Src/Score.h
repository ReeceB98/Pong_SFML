#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Score
{
public:

	// Constructor & Destructor
	Score();
	~Score();

	void Initialize();
	void SetFont(std::string fontPath);
	void SetText(std::string textPhrase);
	void SetPosition(float x, float y);
	void SetCharacterSize(float size);
	void SetScore();
	int GetScore();
	void Render(sf::RenderWindow& window);

private:

	sf::Font* font;
	sf::Text* text;

	int score;
};

