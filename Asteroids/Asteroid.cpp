#include "Asteroid.hpp"

Asteroid::Asteroid(int rectX, int rectY) : speed(0), velocity(sf::Vector2f(0, 0)), angle(0)
{
	asteroidTexture = new sf::Texture();

	if (asteroidTexture->loadFromFile("../asteroids.png", sf::IntRect(rectX, rectY, 50, 50))) // schauen ob man die texture nur einmal lädt
	{
		asteroidSprite.setTexture(*asteroidTexture);
		asteroidSprite.setOrigin(asteroidSprite.getGlobalBounds().width / 2, asteroidSprite.getGlobalBounds().height / 2);
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> disAngle(-pi, pi);
	std::uniform_real_distribution<> disSpeed(100, 200);

	speed = disSpeed(gen);
	angle = disAngle(gen);

	direction = sf::Vector2f(cos(angle), sin(angle));
	SetRandomStartPosition();
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(sf::Time deltaTime)
{
	velocity = speed * direction;
	asteroidSprite.move(velocity * deltaTime.asSeconds());
	OutOfBounds();
}

void Asteroid::Render(sf::RenderWindow& window)
{
	window.draw(asteroidSprite);
}

void Asteroid::OutOfBounds()
{
	if (asteroidSprite.getPosition().x < 0)
	{
		asteroidSprite.setPosition(800, asteroidSprite.getPosition().y);
	}
	if (asteroidSprite.getPosition().x > 800)
	{
		asteroidSprite.setPosition(0, asteroidSprite.getPosition().y);
	}
	if (asteroidSprite.getPosition().y < 0)
	{
		asteroidSprite.setPosition(asteroidSprite.getPosition().x, 600);
	}
	if (asteroidSprite.getPosition().y > 600)
	{
		asteroidSprite.setPosition(asteroidSprite.getPosition().x, 0);
	}
}

void Asteroid::SetRandomStartPosition()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disDirection(0, 3); // 0: oben, 1: unten, 2: links, 3: rechts
	std::uniform_real_distribution<> disPosX(0, 800); // Bildschirmbreite
	std::uniform_real_distribution<> disPosY(0, 600); // Bildschirmhöhe

	int direction = disDirection(gen);
	sf::Vector2f position;

	switch (direction)
	{
	case 0: // oben
		position = sf::Vector2f(disPosX(gen), -50);
		break;
	case 1: // unten
		position = sf::Vector2f(disPosX(gen), 650);
		break;
	case 2: // links
		position = sf::Vector2f(-50, disPosY(gen));
		break;
	case 3: // rechts
		position = sf::Vector2f(850, disPosY(gen));
		break;
	}

	asteroidSprite.setPosition(position);
}


