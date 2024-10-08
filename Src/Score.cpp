#include "Score.h"

Score::Score() : font(font = new sf::Font()), text(text = new sf::Text()){}

Score::~Score()
{
	delete font;
	delete text;
}

void Score::Initialize()
{
	//SetFont("C:/VisualStudio/Pong_SFML/Src/digitalix.ttf");
	//SetText("0");
}

void Score::SetFont(std::string fontPath)
{
	if (!font->loadFromFile(fontPath))
	{
		std::cout << "Font did not load from file.\n";
	}

	text->setFont(*font);
}

void Score::SetText(std::string textPhrase)
{
	text->setString(textPhrase);
}

void Score::SetPosition(float x, float y)
{
	text->setPosition(x, y);
}

void Score::SetCharacterSize(float size)
{
	text->setCharacterSize(size);
}

void Score::SetScore()
{
	score++;
	text->setString(std::to_string(score));
}

int Score::GetScore()
{
	return score;
}

void Score::Render(sf::RenderWindow& window)
{
	window.draw(*text);
}
