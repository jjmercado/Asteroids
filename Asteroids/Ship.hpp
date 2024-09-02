#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.hpp"
#include <list>
#include <vector>
#include "Asteroid.hpp"

class Ship
{
	public:
		Ship();
		~Ship();
		void Events(sf::Event event);
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);
		void Collision(std::list<Asteroid>& asteroids);
		std::list<Bullet*>& GetBullets();

	private:
		sf::Image shipImage;
		sf::IntRect shipRect;
		sf::Texture* shipTextureCollision;
		sf::Sprite shipSpriteCollision;
		sf::Texture shipTexture;
		sf::Sprite shipSprite;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		bool isThrusting;
		bool isRotatingLeft;
		bool isRotatingRight;
		bool isInvincible;
		float speed;
		float rotationSpeed;
		float heading;
		void ApplyThrust(sf::Time deltaTime);
		void OutOfBounds();
		std::list<Bullet*> bullets;
		sf::Time invincibleTime;
		sf::Time blinkInterval;
};

