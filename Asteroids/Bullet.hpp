#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
	public:
		Bullet(sf::Vector2f shipPosition, float shipRotation);
		~Bullet();
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);
		bool OutOfBounds();

	private:
		sf::CircleShape bulletShape;
		sf::Vector2f bulletPos;
		sf::Vector2f shipPosition;
		float shipRotation;
		static int bulletCount;
};

