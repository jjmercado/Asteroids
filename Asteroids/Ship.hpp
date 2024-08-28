#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.hpp"

class Ship
{
	public:
		Ship();
		~Ship();
		void Events(sf::Event event);
		void Update(sf::Time deltaTime);
		void Render(sf::RenderWindow& window);

	private:
		sf::Texture shipTexture;
		sf::Sprite shipSprite;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		bool isThrusting;
		bool isRotatingLeft;
		bool isRotatingRight;
		float speed;
		float rotationSpeed;
		float heading;
		void ApplyThrust(sf::Time deltaTime);
		void OutOfBounds();
		Bullet bullet;
};

