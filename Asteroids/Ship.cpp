#include "Ship.hpp"

Ship::Ship() : heading(0), speed(400), rotationSpeed(8), isThrusting(false), isRotatingLeft(false), isRotatingRight(false), acceleration(sf::Vector2f(0, 0)), velocity(sf::Vector2f(0, 0)), isInvincible(false), invincibleTime(sf::Time::Zero), blinkInterval(sf::milliseconds(200))
{
	if (shipTexture.loadFromFile("../assets/ship.png"))
	{
		shipSprite.setTexture(shipTexture);
		shipSprite.setPosition(400, 300);
		shipSprite.setOrigin(shipSprite.getGlobalBounds().width / 2, shipSprite.getGlobalBounds().height / 2);
	}

	shipSprite.setRotation(heading);

	shipRect = sf::IntRect(shipSprite.getPosition().x, shipSprite.getPosition().y, shipSprite.getGlobalBounds().width, shipSprite.getGlobalBounds().height);
	//shipImage.create(shipSprite.getGlobalBounds().width, shipSprite.getGlobalBounds().height, sf::Color::Green);
	//shipTextureCollision = new sf::Texture();
	//shipTextureCollision->loadFromImage(shipImage);
	//shipSpriteCollision.setTexture(*shipTextureCollision);
	//shipSpriteCollision.setOrigin(shipSpriteCollision.getGlobalBounds().width / 2, shipSpriteCollision.getGlobalBounds().height / 2);
	//shipSpriteCollision.setPosition(shipSprite.getPosition());
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

		if (event.key.code == sf::Keyboard::Space)
		{
			bullets.push_back(new Bullet(shipSprite.getPosition(), heading));
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
	if (isInvincible) 
	{
		invincibleTime -= deltaTime;
		if (invincibleTime <= sf::Time::Zero) 
		{
			isInvincible = false;
			shipSprite.setColor(sf::Color::White);
		}
		else 
		{
			// Blinkeffekt
			int blinkPhase = static_cast<int>(invincibleTime.asMilliseconds() / blinkInterval.asMilliseconds()) % 2;
			shipSprite.setColor(blinkPhase == 0 ? sf::Color::Transparent : sf::Color::White);
		}
	}

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
		ApplyThrust(deltaTime);
	}

	for (auto it = bullets.begin(); it != bullets.end();)
	{
		Bullet* bullet = *it;
		if (bullet != nullptr)
		{
			bullet->Update(deltaTime);
			if (bullet->OutOfBounds())
			{
				delete bullet;
				it = bullets.erase(it);
			}
			else
			{
				++it;
			}
		}
		else
		{
			++it;
		}
	}

	heading = shipSprite.getRotation();
	shipSprite.move(velocity * deltaTime.asSeconds());
	shipSpriteCollision.move(velocity * deltaTime.asSeconds());
	velocity *= 0.99f;
	OutOfBounds();
	shipRect = sf::IntRect(shipSprite.getPosition().x, shipSprite.getPosition().y, shipSprite.getGlobalBounds().width, shipSprite.getGlobalBounds().height);
}

void Ship::Render(sf::RenderWindow& window)
{
	window.draw(shipSprite);
	window.draw(shipSpriteCollision);

	for (auto bullet : bullets)
	{
		if (bullet != nullptr)
		{
			bullet->Render(window);
		}
	}
}

void Ship::Collision(std::list<Asteroid>& asteroids)
{
	if (!isInvincible)
	{
		for (auto& asteroid : asteroids)
		{
			if (shipRect.intersects(asteroid.GetCollisionRect()))
			{
				shipSprite.setPosition(400, 300);
				shipSpriteCollision.setPosition(400, 300);

				isInvincible = true;
				invincibleTime = sf::seconds(2.f);
				shipSprite.setColor(sf::Color::Transparent);
			}
		}
	}

	for (auto it = bullets.begin(); it != bullets.end();)
	{
		Bullet* bullet = *it;
		if (bullet != nullptr)
		{
			for (auto iter = asteroids.begin(); iter != asteroids.end();)
			{
				Asteroid& asteroid = *iter;
				if (bullet != nullptr)
				{
					if (bullet->GetBulletRect().intersects(asteroid.GetCollisionRect()))
					{
						delete bullet;
						bullet = nullptr;
						it = bullets.erase(it);
						if (asteroid.GetScale().x > 0.25f)
						{
							for (int i = 0; i < 2; i++)
							{
								asteroids.push_back(Asteroid(asteroid.GetTexture(), asteroid.GetPosition(), asteroid.GetScale() * 0.5f));
							}
						}
						iter = asteroids.erase(iter);
					}
					else
					{
						++iter;
					}
				}
				else
				{
					++iter;
				}
			}
			if(it != bullets.end())
				++it;
		}
		else
		{
			++it;
		}
	}
}

std::list<Bullet*>& Ship::GetBullets()
{
	return bullets;
}

void Ship::ApplyThrust(sf::Time deltaTime)
{
	acceleration = sf::Vector2f(cos(heading * 3.14159265 / 180) * speed * deltaTime.asSeconds(), sin(heading * 3.14159265 / 180) * speed * deltaTime.asSeconds());
	velocity += acceleration;
}

void Ship::OutOfBounds()
{
	if (shipSprite.getPosition().x > 800)
	{
		shipSprite.setPosition(0, shipSprite.getPosition().y);
	}
	if (shipSprite.getPosition().x < 0)
	{
		shipSprite.setPosition(800, shipSprite.getPosition().y);
	}
	if (shipSprite.getPosition().y > 600)
	{
		shipSprite.setPosition(shipSprite.getPosition().x, 0);
	}
	if (shipSprite.getPosition().y < 0)
	{
		shipSprite.setPosition(shipSprite.getPosition().x, 600);
	}
}

void Ship::Reset()
{
	shipSprite.setPosition(400, 300);
	shipSpriteCollision.setPosition(400, 300);
	shipSprite.setRotation(0);
	velocity = sf::Vector2f(0, 0);
	acceleration = sf::Vector2f(0, 0);
	isThrusting = false;
	isRotatingLeft = false;
	isRotatingRight = false;
	isInvincible = false;
	invincibleTime = sf::Time::Zero;
	shipSprite.setColor(sf::Color::White);
	for (auto bullet : bullets)
	{
		delete bullet;
	}
	bullets.clear();
}
