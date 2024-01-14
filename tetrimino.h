#pragma once
#include<SFML/Graphics.hpp>

class tetrimino
{
protected:
	int** arr;
	sf::Color clr;
	int rot;
	int x, y;
public:
	tetrimino()
	{
		arr = new int* [4];
		for (int i = 0; i < 4; i++)
		{
			arr[i] = new int[4];
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				arr[i][j] = 0;
			}
		}
		rot = 0;
		x = 188;
		y = 68;
	}
	virtual void rotation(int r)
	{
	}
	virtual void drop(int r,int** ar)
	{
	}
	virtual void draw(sf::RenderWindow& window,int**ar)
	{
	}
	virtual void  movel(int r,int **ar)
	{
	}
	virtual void mover(int r,int **ar)
	{
	}
	virtual void moved(int r,int **ar)
	{
	}
	virtual void rotate (int r)
	{
	}
	void setcol(sf::Color colour)
	{
		clr = colour;
	}
	void setrot(int a)
	{
		rot = a;
	}
	int getlocationx()
	{
		return x;
	}
	int getlocationy()
	{
		return y;
	}
	void setlocationx(int a)
	{
		x = a;
	}
	void setlocationy(int a)
	{
		y = a;
	}
	virtual bool stopgame(int **ar)
	{
		for (int i = 0; i < 10; i++)
		{
			if (ar[0][i] != 0)
			{
				return true;
			}
		}
		return false;
	}
	virtual bool landed()
	{
		return 0;
	}
	sf::Color getboardcol(int a)
	{
		if (a == 0)
		{
			return sf::Color::Transparent;
		}
		if (a == 1)
		{
			return sf::Color::Red;
		}
		if (a == 2)
		{
			return sf::Color::Color(222, 200, 55);
		}
		if (a == 3)
		{
			return sf::Color::Color(70, 130, 180);
		}
		if (a == 4)
		{
			return sf::Color::Color(75, 0, 130);
		}
		if (a == 5)
		{
			return sf::Color::Color(255, 140, 0);
		}
		if (a == 6)
		{
			return sf::Color::Color(0, 0, 128);
		}
		if (a == 7)
		{
			return sf::Color::Color(50, 205, 50);
		}

	}
	void drawb(sf::RenderWindow& window,int **ar)
	{
		const int squareSize1 = 20;
		const int padding1 = 2;
		for (int r = 0; r < 20; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				const int x = 100 + padding1 + c * (squareSize1 + padding1);// calculate position of the square
				const int y = 90 + padding1 + r * (squareSize1 + padding1);
				sf::Color color = getboardcol(ar[r][c]);
				sf::RectangleShape square(sf::Vector2f(squareSize1, squareSize1));
				square.setOutlineThickness(1);
				square.setOutlineColor(sf::Color::Black);
				square.setFillColor(color);
				square.setPosition(x, y);
				window.draw(square);
			}
		}
	}
	virtual ~tetrimino()
	{
		for (int i = 0; i < 4; i++)
		{
			delete arr[i];
		}
		delete arr;
	}
};