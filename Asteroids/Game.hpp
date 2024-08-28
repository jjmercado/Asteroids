#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ship.hpp"
#include "Asteroid.hpp"
#include <vector>

class Game
{
	public:
		Game();
		~Game();
		void Run(sf::RenderWindow& window);

	private:	
		void Events(sf::RenderWindow& window);
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);
		sf::Clock fpsClock;
		unsigned int frameCount;
		Ship ship;
		std::vector<Asteroid> asteroids;
		sf::Texture	asteroidTexture;
		std::vector<sf::Texture> asteroidTextures;
};

