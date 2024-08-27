#include "Ship.hpp"

Ship::Ship() : heading(0), speed(400), rotationSpeed(8), isThrusting(false), isRotatingLeft(false), isRotatingRight(false), acceleration(sf::Vector2f(0, 0)), velocity(sf::Vector2f(0, 0))
{
	if (shipTexture.loadFromFile("../ship.png"))
	{
		shipSprite.setTexture(shipTexture);
		shipSprite.setPosition(400, 300);
		shipSprite.setOrigin(shipSprite.getGlobalBounds().width / 2, shipSprite.getGlobalBounds().height / 2);
	}

	shipSprite.setRotation(heading);
}

Ship::~Ship()
{
}

void Ship::Events(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			isRotatingLeft = true;
		}
		if (event.key.code == sf::Keyboard::Right)
		{
			isRotatingRight = true;
		}
		if (event.key.code == sf::Keyboard::Up)
		{
			isThrusting = true;
		}
	}

	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Left)
		{
			isRotatingLeft = false;
		}
		if (event.key.code == sf::Keyboard::Right)
		{
			isRotatingRight = false;
		}
		if (event.key.code == sf::Keyboard::Up)
		{
			isThrusting = false;
		}
	}
}

void Ship::Update(sf::Time deltaTime)
{
	if (isRotatingLeft)
	{
		shipSprite.rotate(-rotationSpeed);
	}
	if (isRotatingRight)
	{
		shipSprite.rotate(rotationSpeed);
	}
	if (isThrusting)
	{
		ApplyForce(deltaTime);
	}

	heading = shipSprite.getRotation();
	shipSprite.move(velocity * deltaTime.asSeconds());
}

void Ship::Render(sf::RenderWindow& window)
{
	window.draw(shipSprite);
}

void Ship::ApplyForce(sf::Time deltaTime)
{
	acceleration = sf::Vector2f(cos(heading * 3.14159265 / 180) * speed * deltaTime.asSeconds(), sin(heading * 3.14159265 / 180) * speed * deltaTime.asSeconds());
	velocity += acceleration;
}
