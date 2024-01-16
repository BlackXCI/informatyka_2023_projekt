#include "Menu.h"
#include "Gra.h"
#include "Gracz.h"
#include "Pocisk.h"
#include "Przeciwnik.h"
//#include "Gra.h"
#include<time.h>
#include <fstream>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    //Gra gra;
    Menu menu;
    Gra gra;
    Gracz gracz;
    int menustate = 0;
    int wybor = 0;
    std::string imieGracz;
    bool wpisane = false;
    bool zapis = false;

    sf::Font imiefont;
    imiefont.loadFromFile("Fonts/BlackOpsOne-Regular.ttf");

   


    sf::RenderWindow window(sf::VideoMode(800, 600), "Projekt Informatyka", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(false);

    sf::Text textImie;
    textImie.setFont(imiefont);
    textImie.setCharacterSize(35);
    textImie.setFillColor(sf::Color::White);
    textImie.setPosition(window.getSize().x / 2.f - textImie.getGlobalBounds().width / 2 - 220.f, 0);
    textImie.setString("Wprowadz swoje imie: ");

    sf::RectangleShape inputBox(sf::Vector2f(200, 30));
    inputBox.setPosition(window.getSize().x / 2.f - inputBox.getGlobalBounds().width / 2 - 15.f, 50);
    inputBox.setFillColor(sf::Color::White);


    sf::Text inputImie;
    inputImie.setFont(imiefont);
    inputImie.setCharacterSize(20);
    inputImie.setFillColor(sf::Color::Black);
    inputImie.setPosition(window.getSize().x / 2.f - inputImie.getGlobalBounds().width / 2 - 110.f, 53);
    inputImie.setString("");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.Event::type == sf::Event::Closed)
                window.close();
            else if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
                menustate = 0;

            else if (event.type == sf::Event::TextEntered && !wpisane)
            {
                if (event.text.unicode == 8 && !imieGracz.empty()) {
                    imieGracz.pop_back();
                }
                else if (event.text.unicode == 13)
                {
                    wybor = 1;
                    wpisane = true;
                }
                else if (event.text.unicode >= 32 && event.text.unicode < 128)
                {
                    imieGracz += static_cast<char>(event.text.unicode);
                }
            }
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
            if (wybor == 0)
            {
                inputImie.setString(imieGracz);

                window.clear(sf::Color(30, 30, 30));
                window.draw(textImie);
                window.draw(inputBox);
                window.draw(inputImie);
            }
            else if (wybor == 1)
            {
                window.clear();
                //Init

                //gra.updatePollEvent();

                if (gra.getGraczHP() > 0)
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
                if (gra.getGraczHP() <= 0)
                {

                    std::ofstream file("wyniki.txt", std::ios::app);
                    if (file.is_open() && !zapis)
                    {
                        file <<"Gracz: "<< imieGracz << " Wynik: " <<gra.getPunkty() << std::endl;
                        file.close();
                        zapis = true;
                    }
                    else
                    {
                        menustate = 0;
                        window.clear();
                    }

                }
            }


        }
        window.display();
    }


    return 0;
}