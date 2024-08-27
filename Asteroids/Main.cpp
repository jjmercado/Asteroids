#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");
	Game game;
	game.Run(window);

	return 0;
}