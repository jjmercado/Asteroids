#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <cmath>
#include <iostream>

class Asteroid
{
	public:
		Asteroid(sf::Texture& texture);
		Asteroid(sf::Texture& texture, sf::Vector2f position, sf::Vector2f scale);
		~Asteroid();
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);
		sf::IntRect GetCollisionRect();
		void BreakAsteroid(sf::Vector2f oldPosition);
		sf::Vector2f GetPosition();
		sf::Vector2f GetScale();

	private:
		sf::Image asteroidImage;
		sf::IntRect asteroidRect;
		sf::Texture* asteroidTextureCollision;
		sf::Sprite asteroidSpriteCollision;
		sf::Sprite asteroidSprite;
		sf::Texture* asteroidTexture;
		sf::Vector2f velocity;
		sf::Vector2f direction;
		float speed;
		const float pi = 3.14159265;
		float angle;
		void OutOfBounds();
		void SetRandomStartPosition();
};

