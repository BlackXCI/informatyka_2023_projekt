#include "Gracz.h"

void Gracz::initVeriables()
{
	this->movementSpeed = 1.5f;
	this->pociskCooldownMax = 17.f;
	this->pociskCooldown = this->pociskCooldownMax;

	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Gracz::initTexture()
{
	if (!this->texture.loadFromFile("Textures/gracz.png"))
	{
		std::cout << "Nie mozna bylo wczytac tekstury gracza" << "\n";
	}
}

void Gracz::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(0.1f, 0.1f);
	this->sprite.setPosition(400, 550);
}


Gracz::Gracz()
{
	this->initVeriables();

	this->initTexture();
	this->initSprite();
}

Gracz::~Gracz()
{

}

const sf::Vector2f& Gracz::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Gracz::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Gracz::getHP() const
{
	return this->hp;
}

const int& Gracz::getHPMax() const
{
	return this->hpMax;
}


void Gracz::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Gracz::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Gracz::setHP(const int hp)
{
	this->hp = hp;
}

void Gracz::loseHP(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Gracz::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Gracz::canAttack()
{
	if (this->pociskCooldown >= this->pociskCooldownMax)
	{
		this->pociskCooldown = 0.5f;
		return true;
	}
	return false;
}

void Gracz::updateAtak()
{
	if (this->pociskCooldown < this->pociskCooldownMax)
		this->pociskCooldown += 1.f;
}

//Funkcje
void Gracz::update()
{
	this->updateAtak();
}

void Gracz::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
