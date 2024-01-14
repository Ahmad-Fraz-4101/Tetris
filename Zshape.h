#pragma once
#include"tetrimino.h"
#include"well.h";

class Zshape :public tetrimino 
{
public:
	int a;//variable used for landing
	Zshape()
	{
		setcol(sf::Color::Red);
		setrot(0);
		setlocationx(188);
		setlocationy(90);
		a = 0;
		arr[1][0] = 1;
		arr[1][1] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;

	}
	
	void rotate(int r)
	{
		int o = 0;
		int p = 0;
		o = ((getlocationy() - 88) / 20);
		p = ((getlocationx() - 100) / 20);
		
		if (r == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					arr[i][j] = 0;
				}
			}
			if (p == 8)
			{
				setlocationx(getlocationx() - 22);
			}
			arr[1][0] = 1;
			arr[1][1] = 1;
			arr[2][1] = 1;
			arr[2][2] = 1;

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
			
			arr[1][2] = 1;
			arr[2][2] = 1;
			arr[2][1] = 1;
			arr[3][1] = 1;
			
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
			if (p == -1)
			{
				setlocationx(getlocationx() + 22);
			}

			arr[2][0] = 1;
			arr[2][1] = 1;
			arr[3][1] = 1;
			arr[3][2] = 1;
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
			

			arr[1][1] = 1;
			arr[2][1] = 1;
			arr[2][0] = 1;
			arr[3][0] = 1;
		}
	}
	void fix(int i,int j,int r1,int **ar)
	{
		if (r1 == 0)
		{
			ar[i][j] = 1;
			ar[i][j + 1] = 1;
			ar[i + 1][j + 1] = 1;
			ar[i + 1][j + 2] = 1;
		}
		if (r1 == 1)
		{
		    ar[i][j + 2] = 1;
			ar[i+1][j + 2] = 1;
			ar[i + 2][j + 1] = 1;
			ar[i + 1][j + 1] = 1;
		}
		if (r1 == 2)
		{
			if (i < 18)
			{
				ar[i + 2][j] = 1;
				ar[i + 2][j + 1] = 1;
			}
			if (i < 17)
			{
				ar[i + 3][j + 1] = 1;
				ar[i + 3][j + 2] = 1;
			}
	    }
		if (r1 == 3)
		{
			ar[i][j + 1] = 1;
			ar[i + 1][j] = 1;
			ar[i + 2] [j] = 1;
			ar[i + 1][j + 1] = 1;
			
		}
		
	}
	bool landed()
	{
		if (a == 0)
			return false;
		else return true;
	}
	
	void movel(int r,int**ar)
	{
		int i = 0;
		int j = 0;
	
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		if (r == 0)
		{
			if(i>=0&&j>=0)
				if (getlocationx() >= 102 && (ar[i][j - 1] == 0) && (ar[i + 1][j] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}
		if (r == 2)
		{
			if (i >= 0 && j >= 0)
				if (getlocationx() >= 102 && (ar[i+2][j-1] == 0) && (ar[i + 3][j] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}
		if (r == 1)
		{
			if (i >= 0 && j >= 0)
				if (getlocationx() >= 80 && (ar[i ][j + 1] == 0) && (ar[i + 1][j] == 0) && (ar[i + 2][j] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}
		if (r == 3)
		{
			if (i >= 0 && j >= 0)
				if (getlocationx() >= 102 && (ar[i][j] == 0) && (ar[i +1][j-1] == 0) && (ar[i + 2][j-1] == 0))
				{
					setlocationx(getlocationx() - 22);
				}
		}

	}
	void mover(int r,int **ar)
	{
		int i = 0;
		int j = 0;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		

		if (r == 0)
		{
			if (i >= 0 && j >= 0)
				if (getlocationx() <= 242 && (ar[i][j +2] == 0) && (ar[i+1 ][j+3] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
		}
		if (r == 2)
		{
			if (i >= 0 && j >= 0)
				if (getlocationx() <= 242 && (ar[i + 2][j +2] == 0) && (ar[i + 3][j+3] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
		}
		if (r == 1)
		{
			if ( i>=0 &&j>=0)
				if (getlocationx() <= 242 && (ar[i][j + 3] == 0) && (ar[i + 1][j+3] == 0) && (ar[i + 2][j+2] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
			if (j == -1)
			{
				setlocationx(getlocationx() + 22);
			}
		}
		if (r == 3)
		{
			if ( i>=0&&j>=0)
				if (getlocationx() <= 262 && (ar[i][j+2] == 0) && (ar[i + 1][j +2] == 0) && (ar[i + 2][j +1] == 0))
				{
					setlocationx(getlocationx() + 22);
				}
		}
	}
	void moved(int r,int **ar)
	{
		a = 0;
		int i = 0;
		int j = 0;
		int r1 = r;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
		
		if (r == 0)
		{
			if (i < 18 && (ar[/*for first*/i + 2][j + 1] == 0) && (ar[/*for second*/i + 2][j + 2] == 0) && (ar[/*for second*/i + 1][j] == 0))
			{

				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1,ar);
				setrot(0);
				a = 1;
				setlocationx(166);
				setlocationy(68);
			}
		}
		else if (r == 1)
		{
			if (i < 17 && (ar[/*for first*/i + 1 + 2][j + 1] == 0) && (ar[/*for second*/i + 1 + 1][j + 2] == 0))
			{
				setlocationy(getlocationy() + 22);

			}
			else
			{
				
				fix(i, j, r1,ar);
				setrot(0);
				a = 1;
				setlocationx(166);
				setlocationy(68);

			}
		}
		if (r == 2)
		{
			if (((getlocationy() - 90) / 20) < 16 && (ar[/*for first*/i + 3][j] == 0) && (ar[/*for second*/i + 4][j + 1] == 0) && (ar[/*for second*/i + 4][j + 2] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				
				fix(i, j, r1,ar);
				setrot(0);
				a = 1;
				setlocationx(166);
				setlocationy(68);
			}
		}
		else if (r == 3)
		{
			if (((getlocationy() - 90) / 20) < 17 && (ar[/*for first*/i + 3][j] == 0) && (ar[/*for second*/i + 2][j + 1] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1,ar);
				setrot(0);
				a = 1;
				setlocationx(166);
				setlocationy(68);
			}
		}
	}
	void drop(int r,int**ar)
	{
		a = 0;
		int i = 0;
		int j = 0;
		int r1 = r;
		i = ((getlocationy() - 90) / 21)+1;
		j = ((getlocationx() - 100) / 20);
	
		if (r == 0)
		{
			if (i < 18 && (ar[/*for first*/i + 2][j + 1] == 0) && (ar[/*for second*/i + 2][j + 2] == 0) && (ar[i + 1][j] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1,ar);
				a = 1;
				setlocationx(166);
				setlocationy(68);
			}
		}

		else if (r == 1)
		{
			if (((getlocationy() - 90) / 20) < 17 && (ar[/*for first*/i + 3][j + 1] == 0) && (ar[/*for second*/i + 2][j + 2] == 0))
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1,ar);
				a = 1;
				setlocationx(166);
				setlocationy(68);
				
			}
		}
		if (r == 2)
		{
			if (i < 16 && (ar[/*for first*/i + 3][j ] == 0) && (ar[/*for second*/i + 4][j + 1] == 0)  && (ar[/*for second*/i + 4][j + 2] == 0) )
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1, ar);
				a = 1;
				setlocationx(166);
				setlocationy(68);
				
			}
		}
		else if (r == 3)
		{
			if (((getlocationy() - 90) / 20) < 17 && (ar[/*for first*/i + 3][j] == 0) && (ar[/*for second*/i + 2][j + 1] == 0) )
			{
				setlocationy(getlocationy() + 22);
			}
			else
			{
				fix(i, j, r1,ar);
				a = 1;
				setlocationx(166);
				setlocationy(68);
				
			}
		}

	}
	
	void draw(sf::RenderWindow& window,int **ar)
	{
		const int squareSize = 20;
		const int padding = 2;
		for (int r = 0; r < 4; r++)
		{
			for (int c = 0; c < 4; c++)
			{
				
				int x = getlocationx() + padding + c * (squareSize + padding);
				int y = getlocationy() + padding + r * (squareSize + padding);
				
				sf::Color color = (arr[r][c] == 1) ? sf::Color::Red : sf::Color::Transparent;
				
				sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
				square.setFillColor(color);
				square.setPosition(x, y);
				window.draw(square);
			}
		}
	}
	
};