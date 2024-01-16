#pragma once
#include "Gracz.h"
#include "Pocisk.h"
#include "Przeciwnik.h"
#include <map>
#include<vector>
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



	//void initWindow();
public:
	void initTextures();
	void initGIU(sf::RenderWindow& window);
	void initWorld();
	void initSys();
	void initGracz();
	void initPrzeciwnik();

	Gra();
	virtual ~Gra();



	void run();

	void endApp();



	//void updatePollEvent();
	void updateInput();

	void updateGUI();
	void updateWorld();
	void updateGracz();
	void updateKolizja(sf::RenderWindow& window);
	void updatePocisk();
	void updatePrzeciwnik(sf::RenderWindow& window);
	void updateWalka();
	//void update();
	void renderGUI(sf::RenderWindow& window);
	void renderWorld(sf::RenderWindow& window);
	void renderGracz(sf::RenderWindow& window);
	void renderPocisk(sf::RenderWindow& window);
	void renderPrzeciwnik(sf::RenderWindow& window);
	//void render(sf::RenderWindow& window);
};

