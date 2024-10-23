#include "Playground.h"
#include "Enemy.h"

Playground::Playground()
{
}

Playground* Playground::instantiate()
{
	Behaviour plantBehavior;

	Playground* playground = new Playground();
	Plant* Plant1 = new Plant(sf::Vector2f(10, 50), &plantBehavior, 0);
	Plant* Plant2 = new Plant(sf::Vector2f(10, 150), &plantBehavior, 0);
	Plant* Plant3 = new Plant(sf::Vector2f(10, 250), &plantBehavior, 0);
	Plant* Plant4 = new Plant(sf::Vector2f(10, 350), &plantBehavior, 0);
	playground->mPlants.push_back(Plant1);
	playground->mPlants.push_back(Plant2);
	playground->mPlants.push_back(Plant3);
	playground->mPlants.push_back(Plant4);

	return playground;
}

void Playground::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mPlants.size(); i++)
	{
		sf::CircleShape shape(10.f);
		shape.setFillColor(sf::Color::Green); 
		shape.setPosition(sf::Vector2f(mPlants[i]->getPosition()));
		window.draw(shape);
	}
	if (mEnemy.size() > 0)
	{
		for (int i = 0; i < mEnemy.size(); i++)
		{
			sf::CircleShape shape(10.f);
			shape.setFillColor(sf::Color::Red);
			shape.setPosition(sf::Vector2f(mEnemy[i]->getPosition()));
			window.draw(shape);
		}
	}
}

void Playground::update()
{
	if (mEnemy.size() > 0)
	{
		for (int i = 0; i < mEnemy.size(); i++)
		{
			mEnemy[i]->Update();
		}
	}
}

void Playground::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
	if (event.mouseButton.button == sf::Mouse::Left && event.type == sf::Event::MouseButtonPressed)
	{
		Behaviour enemyBehavior;
		sf::Vector2i   mousePos = sf::Mouse::getPosition(window);
		int y = 0;
		if (mousePos.y >= 0 && mousePos.y < 100)
		{
			y = 50;
		} else if (mousePos.y >= 100 && mousePos.y < 200)
		{
			y = 150;
		} else if (mousePos.y >= 200 && mousePos.y < 300)
		{
			y = 250;
		} else if (mousePos.y >= 300 && mousePos.y < 400)
		{
			y = 350;
		}

		Enemy* enemy = new Enemy(sf::Vector2f(mousePos.x, y), &enemyBehavior);
		mEnemy.push_back(enemy);
	}
}
