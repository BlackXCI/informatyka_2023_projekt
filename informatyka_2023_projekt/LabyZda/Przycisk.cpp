#include "Przycisk.h"


Przycisk::Przycisk(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor)
{
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f, this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f - 3);
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;


}

Przycisk::~Przycisk()
{

}

const bool Przycisk::isPressed() const
{
	if (this->stanPrzycisk == Pressed)
	{
		return true;
	}

	return false;
}



void Przycisk::update(const sf::Vector2f mousePos)
{

	this->stanPrzycisk = Idle;
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->stanPrzycisk = Hover;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->stanPrzycisk = Pressed;
		}
	}

	switch (this->stanPrzycisk)
	{
	case Idle:
		this->shape.setFillColor(this->idleColor);
		break;
	case Hover:
		this->shape.setFillColor(this->hoverColor);
		break;
	case Pressed:
		this->shape.setFillColor(this->pressedColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Green);
	}

}




void Przycisk::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
