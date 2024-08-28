#include "Bullet.hpp"

int Bullet::bulletCount = 0;

Bullet::Bullet(sf::Vector2f shipPosition, float shipRotation) : bulletPos()
{
	this->shipPosition = shipPosition;
	this->shipRotation = shipRotation;
	bulletShape.setRadius(5);
	bulletShape.setFillColor(sf::Color::White);
	bulletShape.setOrigin(bulletShape.getRadius(), bulletShape.getRadius());
	bulletShape.setPosition(shipPosition + bulletPos);
	bulletCount++;
	std::cout << "Bullet created: " << bulletCount << std::endl;
}

Bullet::~Bullet()
{
	bulletCount--;
	std::cout << "Bullet destroyed: " << bulletCount << std::endl;
}

void Bullet::Update(sf::Time deltaTime)
{
	bulletPos = sf::Vector2f(cos(shipRotation * 3.14159265 / 180) * 20, sin(shipRotation * 3.14159265 / 180) * 20);
	bulletShape.move(bulletPos);
}

void Bullet::Render(sf::RenderWindow& window)
{
	window.draw(bulletShape);
}

bool Bullet::OutOfBounds()
{
	if (bulletShape.getPosition().x > 800)
	{
		return true;
	}
	if (bulletShape.getPosition().x < 0)
	{
		return true;
	}
	if (bulletShape.getPosition().y > 600)
	{
		return true;
	}
	if (bulletShape.getPosition().y < 0)
	{
		return true;
	}
	return false;
}
