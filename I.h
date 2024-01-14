#pragma once
#include"tetrimino.h"
#include"well.h"
class Ishape:public tetrimino
{
public:
	int a = 0;
	Ishape()
	{
		setcol(sf::Color::Color(70, 130, 180));
		setrot(0);
		setlocationx(188);
		setlocationy(90);

		arr[0][0] = 3;
		arr[1][0] = 3;
		arr[2][0] = 3;
		arr[3][0] = 3;
	}
	bool landed()
	{
		if (a == 0)
			return false;
		else return true;
	}
	void rotate(int r)

	{
		int r1 = r % 2;
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 88) / 20);
		j = ((getlocationx() - 100) / 20);
	
		if (r1 == 0&&i<17)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			
			arr[0][0] = 3;
			arr[1][0] = 3;
			arr[2][0] = 3;
			arr[3][0] = 3;

		}
		if (r1 == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			if (j == 9)
			{
				setlocationx(getlocationx() - 66);
			}
			if (j == 8)
			{
				setlocationx(getlocationx() - 44);
			}
			if (j == 7)
			{
				setlocationx(getlocationx() -22 );
			}
			arr[1][0] = 3;
			arr[1][1] = 3;
			arr[1][2] = 3;
			arr[1][3] = 3;

		}
	}
	void movel(int r, int** ar)
	{

		int r1 = r % 2;
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 88) / 20);
		j = ((getlocationx() - 100) / 20);
		if (r1 == 0)
		{
			if (getlocationx() >= 102  && (ar[i + 2][j -1] == 0) && (ar[i][j  -1] == 0) && (ar[i + 1][j -1] == 0))
			{if(i>0 && (ar[i - 1][j - 1] == 0))
				
				setlocationx(getlocationx() - 22);
			}
		}
		if (r1 == 1)
		{
			if (getlocationx() >= 102 )
			{if(i>=0 && (ar[i][j - 1] == 0))
				setlocationx(getlocationx() - 22);
			}
		}

	}

	void mover(int r, int** ar)
	{
		int r1 = r % 2;
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 88) / 20);
		j = ((getlocationx() - 100) / 20);
		if (r1 == 0)
		{if(i>0)
			if (getlocationx() <= 286 && (ar[i + 2][j + 1] == 0)&& (ar[i][j +1] == 0) && (ar[i + 1][j+1] == 0) )
			{
				if(i>0 )
					if( (ar[i - 1][j + 1] == 0))
				setlocationx(getlocationx() + 22);
			}
		}
		if (r1 == 1)
		{
			if (j<6 )
			{if(i>=0 && (ar[i][j + 4] == 0))
				setlocationx(getlocationx() + 22);
			}
		}
	}
	void moved(int r, int** ar)
	{
		a = 0;
		int i = 0;
		int j = 0;
		int r1 = r % 2;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);

		if (r1 == 0)
		{
			if (i < 17 && (ar[i + 3][j] == 0))
			{

				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}

		else if (r1 == 1)
		{

			if (i < 19 && (ar[i + 1][j] == 0) && (ar[i + 1][j + 1] == 0) && (ar[i + 1][j + 2] == 0) && (ar[i + 1][j + 3] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
	}
	void drop(int r, int** ar)
	{
		a = 0;
		int i = 0;
		int j = 0;
		int r1 = r%2;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		
		if (r1== 0)
		{
			if (i < 17 && (ar[i + 3][j] == 0))
			{

				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1, ar);				
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		else if (r1 == 1)
		{
			if (i<19 && (ar[i + 1][j ] == 0) && (ar[i + 1][j + 1] == 0) && (ar[i + 1][j+2] == 0) && (ar[i + 1][j + 3] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1, ar);		
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}

	}

	void fix(int i, int j, int r1, int** ar)
	{
		if (r1 == 0)
		{
			if(i>0)
			ar[i-1][j] = 3;
			ar[i][j ] = 3;
			ar[i + 1][j] = 3;
			ar[i + 2][j ] = 3;

		}
		if (r1 == 1)
		{
			ar[i ][j] = 3;
			if(j<7)
			{
				ar[i][j + 1] = 3;
				ar[i][j + 2] = 3;
				ar[i][j + 3] = 3;
			}
		}
	}

	void draw(sf::RenderWindow& window, int** ar)
	{
		const int squareSize = 20;
		const int padding = 2;
		for (int r = 0; r < 4; r++)
		{
			for (int c = 0; c < 4; c++)
			{
				// calculate the position of the square
				int x = getlocationx() + padding + c * (squareSize + padding);
				int y = getlocationy() + padding + r * (squareSize + padding);
				// determine the color of the square based on the array value
				sf::Color color = (arr[r][c] == 3) ? sf::Color::Color(70, 130, 180) : sf::Color::Transparent;
				// create and draw the square
				sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
				square.setFillColor(color);
				square.setPosition(x, y);
				window.draw(square);
				
			}
		}
	}

};
