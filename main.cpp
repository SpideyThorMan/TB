#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int height = 6;
const int width = 100;
const int gravity = 02;
int x, y, score;
enum eDirection{Stop=0, Move};
eDirection dir;

void Setup()
   {
	gameOver = false;
	dir = Stop;
	x = 0;
	y = height / 2;
	score = 0;
   }

void Draw()
{
	system("cls");
	for (int i = 0; i < width; i++)
	    {
		cout << "#";
	    }
	cout << endl;


	
	for (int i = 0; i < height; i++)																						
	{
        for(int j = 0; j < width; j++ )
		   {
			if (j == 0 || j == width-1)
				cout << "#";

			else
				cout << " ";

			if (i == y && j == x)
			{
				cout << "B";
			}

		   }
		cout << endl;
	}

	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;

	




}

void Input()
{
	if (_kbhit())
	   {
		switch (_getch())
		{
		    case ' ':
				dir = Move;
			break;

			case 'p':
				gameOver = true;

				break;
			default:
				dir = Move;
			break;


		}



	   }
}

void Logic()
{
	switch (dir)
	{
	
	case Move:
			y = y-gravity;
		break;
	default:
		break;
	}
	

}

int main()
   {
	Setup();
	while (!gameOver)
	     {
		Draw();
		Input();
		Logic();
	     }
	return 0;
   }
