#include "Menu.h"

Menu::Menu() : font(font = new sf::Font()), text(text = new sf::Text())
{

}

Menu::~Menu()
{
	delete font;
	delete text;
}

sf::FloatRect Menu::GetTextBounds()
{
	return text->getGlobalBounds();
}

void Menu::SetFont(std::string path)
{
	if (!font->loadFromFile(path))
	{
		std::cout << "Error. Font did not load from file.\n";
	}

	text->setFont(*font);
}

void Menu::SetText(std::string phrase)
{
	text->setString(phrase);
}

void Menu::SetPosition(float x, float y)
{
	text->setPosition(x, y);
}

void Menu::SetCharacterSize(int size)
{
	text->setCharacterSize(size);
}

void Menu::SetTextColour(sf::Color colour)
{
	text->setFillColor(colour);
}

void Menu::Render(sf::RenderWindow& window)
{
	window.draw(*text);
}
