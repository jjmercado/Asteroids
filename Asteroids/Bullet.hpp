#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Asteroid.hpp"
#include <vector>

class Bullet
{
	public:
		Bullet(sf::Vector2f shipPosition, float shipRotation);
		~Bullet();
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);
		bool OutOfBounds();
		sf::IntRect GetBulletRect();

	private:
		sf::CircleShape bulletShape;
		sf::Vector2f bulletPos;
		sf::Vector2f shipPosition;
		sf::IntRect bulletRect;
		sf::Image bulletImage;
		sf::Texture bulletTexture;
		sf::Sprite bulletSprite;
		float shipRotation;
};

