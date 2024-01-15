#pragma once
#include "Przeciwnik.h"


class Pocisk
{
private:

	sf::Sprite shape;
	sf::Vector2f direction;
	float movementSpeed;

public:
	Pocisk();
	Pocisk(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
	virtual ~Pocisk();

	const sf::FloatRect getBounds() const;
	void update();
	void render(sf::RenderTarget* target);
};

