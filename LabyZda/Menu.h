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


    sf::Font font;
    sf::Text text;
    sf::Text autor;

    std::map<std::string, Przycisk*> przyciski;

    sf::Texture texturetlomenu;
    sf::Sprite tlomenu;

    Menu* menu;

    void initWindow();
    void initGIU();
    void initWorld();
    void initPrzyciski();

public:
    Menu();
    virtual ~Menu();

    void run();

    const bool& getQuit() const;

    virtual void CheckForQuit();

    virtual void endState();

    void updatePollEvent();
    void updateMousePos();
    void updateGUI();
    void updatePrzyciski();
    void update();
    void renderGUI();
    void renderWorld();
    void renderPrzyciski();
    void render();

};
