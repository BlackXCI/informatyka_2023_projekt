#include "Gra.h"
#include "Gracz.h"
#include "Pocisk.h"
#include "Przeciwnik.h"
#include <map>
#include<vector>

//P Funkcje
/*void Gra::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Projekt Informatyka", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);

}*/


void Gra::initTextures()
{
	this->textures["POCISK"] = new sf::Texture();
	this->textures["POCISK"]->loadFromFile("Textures/pocisk.png");
}

void Gra::initGIU(sf::RenderWindow& window)
{
	if (!this->font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf"))
	{
		std::cout << "Nie udalo sie wczytac czcionki\n";
	}

	this->text.setFont(this->font);
	this->text.setCharacterSize(20);
	this->text.setFillColor(sf::Color::Green);
	this->text.setString("test");

	/*this->Koniec.setFont(this->font);
	this->Koniec.setCharacterSize(60);
	this->Koniec.setFillColor(sf::Color::Green);
	this->Koniec.setString("Koniec Gry");
	this->Koniec.setPosition(window.getSize().x / 2.f - this->Koniec.getGlobalBounds().width / 2, window.getSize().y / 2.f - this->Koniec.getGlobalBounds().height / 2);*/

	this->graczHP.setSize(sf::Vector2f(200.f, 15.f));
	this->graczHP.setFillColor(sf::Color::Green);
	this->graczHP.setPosition(sf::Vector2f(595.f, 5.f));
	this->graczHPB = this->graczHP;
	this->graczHPB.setFillColor(sf::Color(25, 25, 25, 200));

}

void Gra::initWorld()
{
	this->texturetlo.loadFromFile("Textures/tlo.jpg");


	this->tlo.setTexture(this->texturetlo);
}

void Gra::initSys()
{
	this->punkty = 0;
}



void Gra::initGracz()
{
	this->gracz = new Gracz();

}

void Gra::initPrzeciwnik()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}





//Cons/Des
Gra::Gra()
{
	//this->initWindow();
	this->initTextures();
	this->initGIU(*window);
	this->initWorld();
	this->initGracz();
	this->initPrzeciwnik();
}

Gra::~Gra()
{
	delete this->window;


	delete this->gracz;

	for (auto& i : this->textures)
	{
		delete i.second;
	}

	for (auto* i : this->pociski)
	{
		delete i;
	}

	for (auto* i : this->przeciwnicy)
	{
		delete i;
	}


}






//Funkcje

/*void Gra::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		if (this->gracz->getHP() > 0)
		{
			this->update();
		}
		this->render();
	}
}*/

void Gra::endApp()
{

}




/*void Gra::updatePollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	}
}*/

void Gra::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->gracz->move(-1.5f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->gracz->move(1.5f, 0.f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->gracz->canAttack())
	{
		this->pociski.push_back(new Pocisk(this->textures["POCISK"], this->gracz->getPos().x + 14, this->gracz->getPos().y - 30, 0.f, -1.f, 5.f));
	}
}



void Gra::updateGUI()
{
	std::stringstream ss;

	ss << "Punkty: " << this->punkty;

	this->text.setString(ss.str());

	float procent = static_cast<float>(this->gracz->getHP()) / this->gracz->getHPMax();
	this->graczHP.setSize(sf::Vector2f(200.f * procent, this->graczHP.getSize().y));
}

void Gra::updateWorld()
{

}

void Gra::updateGracz()
{
	this->gracz->update();
}

void Gra::updateKolizja(sf::RenderWindow& window)
{
	if (this->gracz->getBounds().left < 0.f)
	{
		this->gracz->setPosition(0.f, this->gracz->getBounds().top);
	}

	else if (this->gracz->getBounds().left + this->gracz->getBounds().width >= window.getSize().x)
	{
		this->gracz->setPosition(window.getSize().x - this->gracz->getBounds().width, this->gracz->getBounds().top);
	}

	if (this->gracz->getBounds().top < 0.f)
	{
		this->gracz->setPosition(this->gracz->getBounds().left, 0.f);
	}

	else if (this->gracz->getBounds().top + this->gracz->getBounds().height >= window.getSize().y)
	{
		this->gracz->setPosition(this->gracz->getBounds().left, window.getSize().y - this->gracz->getBounds().height);
	}


}

void Gra::updatePocisk()
{
	unsigned counter = 0;
	for (auto* pocisk : this->pociski)
	{
		pocisk->update();

		if (pocisk->getBounds().top + pocisk->getBounds().height < 0.f)
		{
			delete this->pociski.at(counter);
			this->pociski.erase(this->pociski.begin() + counter);
			--counter;


		}

		++counter;
	}
}

void Gra::updatePrzeciwnik(sf::RenderWindow& window)
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->przeciwnicy.push_back(new Przeciwnik(rand() % window.getSize().x - 20.f, -150.f));
		this->spawnTimer = 0.f;
	}

	unsigned counter = 0;
	for (auto* przeciwnik : this->przeciwnicy)
	{
		przeciwnik->update();

		if (przeciwnik->getBounds().top > window.getSize().y)
		{
			this->gracz->loseHP(this->przeciwnicy.at(counter)->getDamege());
			delete this->przeciwnicy.at(counter);
			this->przeciwnicy.erase(this->przeciwnicy.begin() + counter);
			--counter;
		}
		else if (przeciwnik->getBounds().intersects(this->gracz->getBounds()))
		{
			this->gracz->loseHP(this->przeciwnicy.at(counter)->getDamege());
			delete this->przeciwnicy.at(counter);
			this->przeciwnicy.erase(this->przeciwnicy.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Gra::updateWalka()
{
	for (int i = 0; i < this->przeciwnicy.size(); ++i)
	{
		bool usuniecie = false;
		for (size_t k = 0; k < this->pociski.size() && usuniecie == false; k++)
		{
			if (this->przeciwnicy[i]->getBounds().intersects(this->pociski[k]->getBounds()))
			{
				this->punkty += this->przeciwnicy[i]->getPoints();

				delete this->przeciwnicy[i];
				this->przeciwnicy.erase(this->przeciwnicy.begin() + i);

				delete this->pociski[k];
				this->pociski.erase(this->pociski.begin() + k);

				usuniecie = true;
			}
		}
	}
}


/*void Gra::update()
{

	this->updateInput();
	this->gracz->update();
	this->updateKolizja();
	this->updatePocisk();
	this->updatePrzeciwnik();
	this->updateWalka();
	this->updateGUI();
	this->updateWorld();



}*/

void Gra::renderGUI(sf::RenderWindow& window)
{
	window.draw(this->text);
	window.draw(this->graczHPB);
	window.draw(this->graczHP);
}

void Gra::renderWorld(sf::RenderWindow& window)
{
	window.draw(this->tlo);
}

void Gra::renderGracz(sf::RenderWindow& window)
{
	this->gracz->render(window);
}

void Gra::renderPocisk(sf::RenderWindow& window)
{
	for (auto* pocisk : this->pociski)
	{
		pocisk->render(window);
	}
}

void Gra::renderPrzeciwnik(sf::RenderWindow& window)
{
	for (auto* przeciwnik : this->przeciwnicy)
	{
		przeciwnik->render(window);
	}
}

/*void Gra::render(sf::RenderWindow& window)
{


	this->renderWorld(window);
	this->gracz->render(window);

	for (auto* pocisk : this->pociski)
	{
		pocisk->render(window);
	}

	for (auto* przeciwnik : this->przeciwnicy)
	{
		przeciwnik->render(window);
	}

	this->renderGUI(window);

	if (this->gracz->getHP() <= 0)
	{
		this->window->draw(this->Koniec);
	}

}*/

