#pragma once
#include "Pocisk.h"
class Gracz
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	float pociskCooldown;
	float pociskCooldownMax;

	int hp;
	int hpMax;

	//P funckje
	void initVeriables();
	void initTexture();
	void initSprite();



public:
	Gracz();
	virtual ~Gracz();

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHP() const;
	const int& getHPMax() const;

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHP(const int hp);
	void loseHP(const int value);

	//Funkcje
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAtak();
	void update();
	void render(sf::RenderTarget& target);
};

