#include "Menu.h"
//#include "Gra.h"
#include<time.h>



int main()
{
    srand(static_cast<unsigned int>(time(0)));

    //Gra gra;
    Menu menu;
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
        }
        if (menustate == 1)
        {

        }
        if (menustate == 0)
        {
            window.clear();
            //menu.updatePollEvent();
            menu.initGIU(window);
            menu.initWorld();
            menu.initPrzyciski();
            //menu.update();
            menu.updateMousePos(window);
            menu.updateGUI();

            menu.updatePrzyciski();
            //this->window->clear();
            menu.renderWorld(window);
            menu.renderGUI(window);
            menu.renderPrzyciski(window);
            
        }
        window.display();
    }


    return 0;
}