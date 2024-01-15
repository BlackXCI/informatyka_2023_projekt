#pragma once
#include "Gracz.h"
#include "Pocisk.h"
#include "Przeciwnik.h"
#include "Menu.h"
class Gra
{
private:
	sf::RenderWindow* window;

	std::map<std::string, sf::Texture*> textures;
	std::vector<Pocisk*> pociski;



	sf::Font font;
	sf::Text text;

	sf::Text Koniec;

	sf::Texture texturetlo;
	sf::Sprite tlo;

	unsigned punkty;

	Gracz* gracz;

	sf::RectangleShape graczHP;
	sf::RectangleShape graczHPB;

	float spawnTimer;
	float spawnTimerMax;
	std::vector<Przeciwnik*> przeciwnicy;



	void initWindow();
	void initTextures();
	void initGIU();
	void initWorld();
	void initSys();
	void initGracz();
	void initPrzeciwnik();
public:
	Gra();
	virtual ~Gra();



	void run();

	void endApp();



	void updatePollEvent();
	void updateInput();

	void updateGUI();
	void updateWorld();
	void updateKolizja();
	void updatePocisk();
	void updatePrzeciwnik();
	void updateWalka();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
}; 