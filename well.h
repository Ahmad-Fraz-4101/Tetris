#pragma once 

#include<SFML/Graphics.hpp>
#include"tetrimino.h"

class well:public tetrimino
{
public:
	int** ar;
	well()
	{
		ar = new int* [20];
		for (int i = 0; i < 20; i++)
		{
			ar[i] = new int[10];
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				ar[i][j] = 0;
			}
		}
	}
	void draw(sf::RenderWindow& window)
	{
		const int squareSize = 20;
		const int padding = 2;
		for (int r = 0; r < 20; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				// calculate the position of the square
				const int x = 100 + padding + c * (squareSize + padding);
				const int y = 90 + padding + r * (squareSize + padding);
				sf::Color color = (ar[r][c] == 1) ? sf::Color::Red : sf::Color::Transparent;
				sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
				square.setOutlineThickness(1);
				square.setOutlineColor(sf::Color::Black);
				square.setFillColor(color);
				square.setPosition(x, y);
				window.draw(square);
			}
		}
	}
	~well()
	{
		for (int i = 0; i < 20; i++)
			delete ar[i];
		delete ar;
	}
};

