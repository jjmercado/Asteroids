#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
	public:
		Bullet();
		~Bullet();
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);

	private:
		sf::CircleShape bulletShape;
};

