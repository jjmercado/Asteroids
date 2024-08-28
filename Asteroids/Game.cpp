#include "Game.hpp"

Game::Game() : frameCount(0), fpsClock(), ship()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 3);

	if (asteroidTexture.loadFromFile("../asteroids.png", sf::IntRect(0, 0, 50, 50)))
	{
		asteroidTextures.push_back(asteroidTexture);
	}
	if (asteroidTexture.loadFromFile("../asteroids.png", sf::IntRect(50, 0, 50, 50)))
	{
		asteroidTextures.push_back(asteroidTexture);
	}
	if (asteroidTexture.loadFromFile("../asteroids.png", sf::IntRect(0, 50, 50, 50)))
	{
		asteroidTextures.push_back(asteroidTexture);
	}
	if (asteroidTexture.loadFromFile("../asteroids.png", sf::IntRect(50, 50, 50, 50)))
	{
		asteroidTextures.push_back(asteroidTexture);
	}

	for (int i = 0; i < 10; i++)
	{
		int randomTexture = dis(gen);
		asteroids.push_back(Asteroid(asteroidTextures[randomTexture]));
	}
}

Game::~Game()
{
}

void Game::Run(sf::RenderWindow& window)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			Events(window);
			Update(TimePerFrame);
			Render(window);

			frameCount++;
			if (fpsClock.getElapsedTime().asSeconds() >= 1.0f)
			{
				std::cout << "FPS: " << frameCount << std::endl;
				frameCount = 0;
				fpsClock.restart();
			}
		}

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

		ship.Events(event);
	}
}

void Game::Update(sf::Time deltaTime)
{
	ship.Update(deltaTime);

	for (auto& asteroid : asteroids)
	{
		asteroid.Update(deltaTime);
	}
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear();
	ship.Render(window);

	for (auto& asteroid : asteroids)
	{
		asteroid.Render(window);
	}
	window.display();
}
