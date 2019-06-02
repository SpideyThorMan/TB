#include <iostream>
using namespace std;

bool gameOver;
const int height = 6;
const int width = 100;
int x, y, score;
enum eDirection{Stop=0, Move};
eDirection dir;

void Setup()
   {
	gameOver = false;
	dir = Stop;
	x = width/2;
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

}

void Logic()
{

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
