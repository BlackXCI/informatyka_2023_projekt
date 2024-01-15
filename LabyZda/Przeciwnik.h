#pragma once
#include "Menu.h"

class Przeciwnik
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int type;
	int speed;
	int hp;
	int hpMax;
	int damage;
	int punkty;

	void initVariables();
	void initTexture();
	void initSprite();

public:
	Przeciwnik(float posy_x, float pos_y);
	virtual ~Przeciwnik();

	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamege() const;

	void update();
	void render(sf::RenderTarget& target);
};

