#include "Przeciwnik.h"

void Przeciwnik::initVariables()
{
	this->type = 0;
	this->speed = 1.5f;
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 1;
	this->punkty = 1;
}

void Przeciwnik::initTexture()
{
	if (!this->texture.loadFromFile("Textures/przeciwnik.png"))
	{
		std::cout << "Nie mozna bylo wczytac tekstury przeciwnika" << "\n";
	}
}

void Przeciwnik::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(0.30f, 0.30f);

}

Przeciwnik::Przeciwnik(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(pos_x, pos_y);
}

Przeciwnik::~Przeciwnik()
{

}

const sf::FloatRect Przeciwnik::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Przeciwnik::getPoints() const
{
	return this->punkty;
}

const int& Przeciwnik::getDamege() const
{
	return this->damage;
}

void Przeciwnik::update()
{
	this->sprite.move(0.f, 0.60f);
}

void Przeciwnik::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
