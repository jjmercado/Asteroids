#pragma once
#include <SFML/Graphics.hpp>

class Asteroid
{
	public:
		Asteroid(int rectX, int rectY);
		~Asteroid();
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);

	private:
		sf::Sprite asteroidSprite;
		sf::Texture asteroidTexture;
		sf::Vector2f velocity;
		sf::Vector2f direction;
		float speed;
};

