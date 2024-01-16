#include "Menu.h"
#include "Gra.h"
#include "Gracz.h"
#include "Pocisk.h"
#include "Przeciwnik.h"
//#include "Gra.h"
#include<time.h>



int main()
{
    srand(static_cast<unsigned int>(time(0)));

    //Gra gra;
    Menu menu;
    Gra gra;
    Gracz gracz;
    int menustate = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Projekt Informatyka", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.Event::type == sf::Event::Closed)
                window.close();
            if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                window.close();
        }
        if (menustate == 0)
        {
            if (menu.GetState() == 1)
            {
                menustate = 1;
            }
            if (menu.GetState() == 2)
            {
                menustate = 2;
            }
            if (menu.GetState() == 3)
            {
                menustate = 3;
            }
            if (menu.GetState() == 4)
            {
                menustate = 4;
            }
            if (menu.GetState() == 0)
            {
                menustate = 0;
            }
        }
        if (menustate == 0)
        {
            window.clear();
            //Init;
            menu.initGIU(window);
            menu.initWorld();
            menu.initPrzyciski();
            //Update;
            menu.updateMousePos(window);
            menu.updateGUI();
            menu.updatePrzyciski();
            //Render;
            menu.renderWorld(window);
            menu.renderGUI(window);
            menu.renderPrzyciski(window);
            
        }
        if (menustate == 1)
        {
            window.clear();
            //Init
            
            //gra.updatePollEvent();
            
            if (gracz.getHP() > 0)
            {
                //Update
                //gra.updatePollEvent();
                gra.updateInput();
                gra.updateGracz();
                gra.updateKolizja(window);
                gra.updatePocisk();
                gra.updatePrzeciwnik(window);
                gra.updateWalka();
                gra.updateGUI();
                gra.updateWorld();
            }
            //Render
            gra.renderWorld(window);
            gra.renderGracz(window);
            gra.renderPocisk(window);
            gra.renderPrzeciwnik(window);
            gra.renderGUI(window);
            if (gracz.getHP() <= 0)
            {
                std::cout << "Stan5";
            }


        }
        window.display();
    }


    return 0;
}