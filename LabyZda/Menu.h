#pragma once
#include "Przycisk.h"

class Menu
{
private:
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    sf::RenderWindow* window;

    bool checkQuit = false;

    int state = 0;


    sf::Font font;
    sf::Text text;
    sf::Text autor;

    std::map<std::string, Przycisk*> przyciski;

    sf::Texture texturetlomenu;
    sf::Sprite tlomenu;

    Menu* menu;

    //void initWindow();
    /*void initGIU(sf::RenderWindow& window);
    void initWorld();
    void initPrzyciski();*/

public:
    void initGIU(sf::RenderWindow& window);
    void initWorld();
    void initPrzyciski();

    Menu();
    virtual ~Menu();

    //void run();


    //virtual void CheckForQuit();

    //virtual void endState();

    void updatePollEvent();
    void updateMousePos(sf::RenderWindow& window);
    void updateGUI();
    void updatePrzyciski();
    //void update();
    void renderGUI(sf::RenderWindow& window);
    void renderWorld(sf::RenderWindow& window);
    void renderPrzyciski(sf::RenderWindow& window);
    //void render(sf::RenderWindow& window);
    int GetState();

};
