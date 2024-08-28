#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
	public:
		Bullet();
		~Bullet();
		void Update(sf::Time deltaTime, float shipRotation);
		void Render(sf::RenderWindow& window);
		void Fire(sf::Vector2f shipPosition, float shipRotation);

	private:
		sf::CircleShape bulletShape;
		sf::Vector2f bulletPos;
};

