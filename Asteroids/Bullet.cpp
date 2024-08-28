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

void Bullet::Update(sf::Time deltaTime)
{
}

void Bullet::Render(sf::RenderWindow& window)
{
	window.draw(bulletShape);
}
