#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
			Events(window);
			Update();
			Render(window);
	}
}

void Game::Events(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void Game::Update()
{
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear();
	window.display();
}
