#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <cmath>
#include <iostream>

class Asteroid
{
	public:
		Asteroid(const sf::Texture& texture);
		Asteroid(const sf::Texture& texture, sf::Vector2f position, sf::Vector2f scale);
		~Asteroid();
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);
		sf::IntRect GetCollisionRect();
		sf::Vector2f GetPosition();
		sf::Vector2f GetScale();
		const sf::Texture& GetTexture();

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

