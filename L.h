#pragma once
#include"tetrimino.h"
#include"well.h"
class Lshape :public tetrimino
{
public:
	int a;
	Lshape()
	{
		setcol(sf::Color::Color(255, 140, 0));
		setrot(0);
		setlocationx(188);
		setlocationy(90);
		a = 0;
		arr[0][0] = 5;
		arr[1][0] = 5;
		arr[2][0] = 5;
		arr[2][1] = 5;
	}

	bool landed()
	{
		if (a == 0)
			return false;
		else return true;
	}

	void rotate(int r)
	{
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 88) / 20);
		j = ((getlocationx() - 100) / 20);
		if (r == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			arr[0][0] = 5;
			arr[1][0] = 5;
			arr[2][0] = 5;
			arr[2][1] = 5;
		}
		if (r == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			if (j == 8)
			{
				setlocationx(getlocationx() - 22);
			}
			arr[0][0] = 5;
			arr[0][1] = 5;
			arr[0][2] = 5;
			arr[1][0] = 5;
		}
		if (r == 2)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			arr[0][0] = 5;
			arr[0][1] = 5;
			arr[1][1] = 5;
			arr[2][1] = 5;
		}
		if (r == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			if (j == 8)
			{
				setlocationx(getlocationx() - 22);
			}
			arr[0][2] = 5;
			arr[1][0] = 5;
			arr[1][1] = 5;
			arr[1][2] = 5;
		}
	}

	void drop(int r, int** ar)
	{
		a = 0;
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		if (r == 0)
		{
			if ( i<18&& (ar[i+2][j] == 0) && (ar[i+2][j + 1] == 0) )
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		else if (r == 1)
		{
			if (i < 19 && (ar[i + 1][j ] == 0) && (ar[i ][j + 1] == 0 && (ar[i][j + 2] == 0)))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		if (r == 2)
		{
			if (i < 18 && (ar[i ][j] == 0) && (ar[i + 2][j + 1] == 0) )
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		else if (r == 3)
		{
			if (i < 19 && (ar[i + 1][j] == 0) && (ar[i + 1][j + 1] == 0) && (ar[i + 1][j + 2] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}

	}

	void moved(int r, int** ar)
	{
		a = 0;
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		if (r == 0)
		{
			if (i < 18 && (ar[i + 2][j] == 0) && (ar[i + 2][j + 1] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);		 
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		else if (r == 1)
		{
			if (i < 19 && (ar[i + 1][j] == 0) && (ar[i][j + 1] == 0 && (ar[i][j + 2] == 0)))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		if (r == 2)
		{
			if (i < 18 && (ar[i][j] == 0) && (ar[i + 2][j + 1] == 0))

			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);
				a = 1;
				setlocationx(188);
				setlocationy(90);
			}
		}
		else if (r == 3)
		{
			if (i < 19 && (ar[i + 1][j] == 0) && (ar[i + 1][j + 1] == 0) && (ar[i + 1][j + 2] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r, ar);			
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
				ar[i - 1][j] = 5;
				ar[i ][j] = 5;
				ar[i + 1][j ] = 5;
				ar[i+1][j + 1] = 5;
		}
		if (r1 == 1)
		{
				ar[i][j ] = 5;
				if (i > 0)
				{
					ar[i - 1][j] = 5;
					ar[i - 1][j + 1] = 5;
					ar[i -1][j + 2] = 5;
				}
		}
		if (r1 == 2)
		{
			if (i >= 0)
			{
				ar[i-1][j + 1] = 5;
				ar[i -1][j] = 5;
			}
     		ar[i ][j + 1] = 5;
			ar[i +1][j + 1] = 5;
		}
		if (r1 == 3)
		{
				ar[i ][j] = 5;
				ar[i ][j + 1] = 5;
				ar[i][j + 2] = 5;
			if(i>0)
			ar[i-1][j + 2] = 5;
		}
	}

	void movel(int r, int** ar)
	{
		int i = 0;
		int j = 0;

		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		
		if (r == 0)
		{
			if (i > 0)
				if (getlocationx() >= 102 && (ar[i-1][j-1] == 0) && (ar[i ][j - 1] == 0) && (ar[i + 1][j - 1] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}
		if (r == 2)
		{
			if (i > 0)
				if (getlocationx() >= 102 && (ar[i][j] == 0) && (ar[i + 1][j ] == 0) && (ar[i-1 ][j -1] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}
		if (r == 1)
		{
			if (i > 0)
				if (getlocationx() >= 102 && (ar[i][j-1] == 0) && (ar[i-1][j - 1] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}
		if (r == 3)
		{
			if (i > 0)
				if (getlocationx() >= 102 && (ar[i-1][j +1] == 0) && (ar[i ][j -1] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}

	}

	void mover(int r, int** ar)
	{
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		if (r == 0)
		{
			if (i > 0 )
				if (getlocationx() <= 264 && (ar[i][j +1] == 0) && (ar[i - 1][j + 1] == 0) && (ar[i + 1][j + 2] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
		}
		if (r == 2)
		{
			if (i >0)
				if (getlocationx() <= 262 && (ar[i - 1][j + 2] == 0) && (ar[i ][j + 2] == 0) && (ar[i+1][j + 2] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
		}
		if (r == 1)
		{
			if (i > 0 )
				if (getlocationx() <= 242 && (ar[i][j + 1] == 0) && (ar[i -1 ][j + 1] == 0) && (ar[i + 1][j + 2] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
			/*if (j == -1)
			{
				setlocationx(getlocationx() + 22);
			}*/
		}
		if (r == 3)
		{
			if (i > 0 )
				if (getlocationx() <= 242 && (ar[i-1][j + 3] == 0) && (ar[/*for second*/i ][j + 3] == 0) )
				{
					setlocationx(getlocationx() + 22);
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
				sf::Color color = (arr[r][c] == 5) ? sf::Color::Color(255, 140, 0) : sf::Color::Transparent;
				// create and draw the square
				sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
				square.setFillColor(color);
				square.setPosition(x, y);
				window.draw(square);
			}
		}
	}
};