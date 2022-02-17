#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "Ball.hpp"
#include "Racket.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong !");
	window.setFramerateLimit(60);

	Ball ball;
	
	Racket leftRacket('L');
	Racket rightRacket('R');

	sf::RectangleShape middleLine(sf::Vector2f(LINE_WIDTH, SCREEN_HEIGHT));
	middleLine.setPosition(SCREEN_WIDTH/2-LINE_WIDTH/2, 0);

	while (window.isOpen())
	{
		sf::Event event;

		window.clear();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Collision between the ball and rackets
		if (ball.getHitBox().intersects(rightRacket.getHitBox()))
		{
			ball.changeDirection(rightRacket.getPosition());
		}
		else if (ball.getHitBox().intersects(leftRacket.getHitBox()))
		{
			ball.changeDirection(leftRacket.getPosition());
		}

		// Controls for the rackets
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			leftRacket.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			leftRacket.moveDown();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rightRacket.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rightRacket.moveDown();
		}

		ball.move();

		unsigned short pointPos = BALL_SIZE;

		while (pointPos < SCREEN_HEIGHT)
		{
			sf::RectangleShape rectangle(sf::Vector2f(LINE_WIDTH, BALL_SIZE));
			rectangle.setPosition(SCREEN_WIDTH/2 - BALL_SIZE/2, pointPos);

			pointPos += BALL_SIZE * 2;

			window.draw(rectangle);
		}

		ball.draw(window);

		leftRacket.draw(window);
		rightRacket.draw(window);

		window.display();
	}

	return 0;
}