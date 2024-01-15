#include "Pocisk.h"


Pocisk::Pocisk()
{

}

Pocisk::Pocisk(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);

	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Pocisk::~Pocisk()
{

}

const sf::FloatRect Pocisk::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Pocisk::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Pocisk::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
