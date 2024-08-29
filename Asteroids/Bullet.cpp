#include "Bullet.hpp"

Bullet::Bullet(sf::Vector2f shipPosition, float shipRotation) : bulletPos(), shipPosition(), shipRotation(), bulletRect(bulletShape.getPosition().x, bulletShape.getPosition().y, 10, 10)
{
	//bulletImage.create(10, 10, sf::Color::Red);
	//bulletTexture.loadFromImage(bulletImage);
	//bulletSprite.setTexture(bulletTexture);
	//bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
	//bulletSprite.setPosition(shipPosition);

	this->shipPosition = shipPosition;
	this->shipRotation = shipRotation;
	bulletShape.setRadius(5);
	bulletShape.setFillColor(sf::Color::White);
	bulletShape.setOrigin(bulletShape.getRadius(), bulletShape.getRadius());
	bulletShape.setPosition(shipPosition + bulletPos);
	bulletRect = sf::IntRect(bulletShape.getPosition().x, bulletShape.getPosition().y, 10, 10);
}

Bullet::~Bullet()
{
}

void Bullet::Update(sf::Time deltaTime)
{
	bulletPos = sf::Vector2f(cos(shipRotation * 3.14159265 / 180) * 20, sin(shipRotation * 3.14159265 / 180) * 20);
	bulletSprite.move(bulletPos);
	bulletShape.move(bulletPos);
	bulletRect = sf::IntRect(bulletShape.getPosition().x, bulletShape.getPosition().y, 10, 10);
}

void Bullet::Render(sf::RenderWindow& window)
{
	window.draw(bulletShape);
	window.draw(bulletSprite);
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

sf::IntRect Bullet::GetBulletRect()
{
	return bulletRect;
}
