#include "Menu.h"

/*void Menu::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Projekt Informatyka", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}*/

void Menu::initGIU(sf::RenderWindow& window)
{
	if (!this->font.loadFromFile("Fonts/Race Sport.ttf"))
	{
		std::cout << "Nie udalo sie wczytac czcionki\n";
	}

	this->text.setFont(this->font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("Space Invaders");
	this->text.setPosition(window.getSize().x / 2.f - this->text.getGlobalBounds().width / 2, 0);

	this->autor.setFont(this->font);
	this->autor.setCharacterSize(15);
	this->autor.setFillColor(sf::Color::White);
	this->autor.setString("Autor: Kacper Korzeb 194511");
	this->autor.setPosition(0, 580);

}

void Menu::initWorld()
{
	this->texturetlomenu.loadFromFile("Textures/tlomenu.jpg");


	this->tlomenu.setTexture(this->texturetlomenu);
}

void Menu::initPrzyciski()
{
	this->przyciski["Gra"] = new Przycisk(50, 150, 150, 50, &this->font, "Nowa Gra", sf::Color(70, 70, 70, 200), sf::Color(70, 70, 150, 200), sf::Color(20, 20, 20, 200));
	this->przyciski["Tabela Wynikow"] = new Przycisk(50, 225, 150, 50, &this->font, "Tabela Wynikow", sf::Color(70, 70, 70, 200), sf::Color(70, 70, 150, 200), sf::Color(20, 20, 20, 200));
	this->przyciski["O projekcie"] = new Przycisk(50, 300, 150, 50, &this->font, "O projekcie", sf::Color(70, 70, 70, 200), sf::Color(70, 70, 150, 200), sf::Color(20, 20, 20, 200));
	this->przyciski["Wyjscie"] = new Przycisk(50, 375, 150, 50, &this->font, "Wyjscie", sf::Color(70, 70, 70, 200), sf::Color(70, 70, 150, 200), sf::Color(20, 20, 20, 200));
}

Menu::Menu()
{
	/*this->initWindow();
	this->initGIU(*window);
	this->initWorld();
	this->initPrzyciski();*/



}

Menu::~Menu()
{
	auto it = this->przyciski.begin();
	for (it = this->przyciski.begin(); it != this->przyciski.end(); ++it)
	{
		delete it->second;
	}
}

/*void Menu::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		this->update();
		this->render(window);
	}
}*/


void Menu::updatePollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Menu::updateMousePos(sf::RenderWindow& window)
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(window);
	this->mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void Menu::updateGUI()
{

}

void Menu::updatePrzyciski()
{
	for (auto& it : this->przyciski)
	{
		it.second->update(this->mousePosView);
	}

	if (this->przyciski["Gra"]->isPressed())
	{
		state = 1;
		std::cout << "Stan 1" << "\n";
	}

	if (this->przyciski["Tabela Wynikow"]->isPressed())
	{
		state = 2;
		std::cout << "Stan 2" << "\n";
	}

	if (this->przyciski["O projekcie"]->isPressed())
	{
		state = 3;
		std::cout << "Stan 3" << "\n";
	}

	if (this->przyciski["Wyjscie"]->isPressed())
	{
		state = 4;
		std::cout << "Stan 4" << "\n";
	}
}

/*void Menu::update()
{
	this->updateMousePos();
	this->updateGUI();

	this->updatePrzyciski();

}*/

void Menu::renderGUI(sf::RenderWindow& window)
{
	window.draw(text);
	window.draw(autor);
}

void Menu::renderWorld(sf::RenderWindow& window)
{
	window.draw(tlomenu);
}

void Menu::renderPrzyciski(sf::RenderWindow& window)
{
	for (auto& it : this->przyciski)
	{
		it.second->render(window);
	}
}

int Menu::GetState()
{
	return state;
}



/*void Menu::render(sf::RenderWindow& window)
{
	this->window->clear();
	this->renderWorld(window);
	this->renderGUI();
	this->renderPrzyciski();
	this->window->display();

}*/


