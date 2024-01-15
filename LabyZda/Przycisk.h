#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<string>
#include<sstream>
#include <map>
#include<vector>

enum stan { Idle = 0, Hover, Pressed };

class Przycisk
{
private:
	short unsigned stanPrzycisk;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;
	sf::RenderWindow* window;


	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;



public:
	Przycisk(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor);
	~Przycisk();

	const bool isPressed() const;



	void update(const sf::Vector2f mousePos);
	void render(sf::RenderWindow& window);


};

