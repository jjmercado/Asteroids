#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");
	window.setFramerateLimit(60);
	Game game;
	game.Run(window);

	return 0;
}