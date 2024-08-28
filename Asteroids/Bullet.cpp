#include "Bullet.hpp"

Bullet::Bullet()
{
	bulletShape.setRadius(5);
	bulletShape.setFillColor(sf::Color::White);
	bulletShape.setOrigin(bulletShape.getRadius(), bulletShape.getRadius());
	bulletShape.setPosition(400, 300);
}

Bullet::~Bullet()
{
}

void Bullet::Update(sf::Time deltaTime, float shipRotation)
{
	bulletShape.move(bulletPos);
}

void Bullet::Render(sf::RenderWindow& window)
{
	window.draw(bulletShape);
}

void Bullet::Fire(sf::Vector2f shipPosition, float shipRotation)
{
	bulletPos = sf::Vector2f(cos(shipRotation * 3.14159265 / 180) * 20, sin(shipRotation * 3.14159265 / 180) * 20);
	bulletShape.setPosition(shipPosition + bulletPos);
}
