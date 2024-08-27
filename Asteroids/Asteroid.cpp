#include "Asteroid.hpp"

Asteroid::Asteroid(int rectX, int rectY) : speed(100), velocity(sf::Vector2f(0, 0))
{
	if (asteroidTexture.loadFromFile("../asteroids.png", sf::IntRect(rectX, rectY, 50, 50)))
	{
		asteroidSprite.setTexture(asteroidTexture);
		asteroidSprite.setPosition(400, 300);
		asteroidSprite.setOrigin(asteroidSprite.getGlobalBounds().width / 2, asteroidSprite.getGlobalBounds().height / 2);
	}

	direction = sf::Vector2f(1, 0);
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(sf::Time deltaTime)
{
	velocity = speed * direction;
	asteroidSprite.move(velocity * deltaTime.asSeconds());
}

void Asteroid::Render(sf::RenderWindow& window)
{
	window.draw(asteroidSprite);
}
