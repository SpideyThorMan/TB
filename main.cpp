#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(0));//to make the program randomize
	char mv;
	char restart = 'y';
	int highscore = 0;
	while (restart == 'y')
       {
		int score = 0;
		bool wasit = true;
		int x = 9;
		int yAxis[5]; // the y-axis of obstacle
		int xAxis[5]; // the x-axis of obstacle
		xAxis[0] = 9;
		xAxis[1] = 18;
		xAxis[2] = 27; // the starting x-axis of obstacle
		for (int i = 0; i < 3; i++)
		  {
			yAxis[i] = (rand() - 1) % 12 + 2;
		  }
		string map[20][30];
		for (int i = 0; i < 20; i++)
		  {
			for (int j = 0; j < 30; j++)
			   {
				if (i == 0 || i == 19 || j == 29 || j == 0)
					map[i][j] = "# ";
				else
					map[i][j] = "  ";
			   }
		  }
		while (wasit == true)
		  {
             for (int i = 0; i < 3; i++)
			  {
				for (int j = 1; j < 19; j++)
				  {
					map[j][xAxis[i]] = "  ";
				  }
			  }
			for (int i = 0; i < 3; i++) //make the obstacle move from right to left
			  {
				xAxis[i]--;
			  }
			for (int i = 0; i < 3; i++) //make the obstacle back to right side if it touched left side
			  {
				for (int j = 1; j < 19; j++)
				  {
					map[j][xAxis[i]] = "* ";
				  }
			  }
			for (int i = 0; i < 3; i++) //to make a hole at the obstacle
			  {
				map[yAxis[i]][xAxis[i]] = "  ";
				map[yAxis[i] + 1][xAxis[i]] = "  ";
				map[yAxis[i] + 2][xAxis[i]] = "  ";
				map[yAxis[i] + 3][xAxis[i]] = "  ";
				map[yAxis[i] + 4][xAxis[i]] = "  ";
			  }
			for (int i = 0; i < 3; i++)
			  {
				if (xAxis[i] == 1)
				  {
					xAxis[i] = 28;
					yAxis[i] = (rand() - 1) % 12 + 2;
				  }
			  }
			map[x][3] = "  ";
			if (kbhit())
			  {
				mv = getch();
				x = x - 3;
			  }
			x++;
			if (x < 1)
				x = 1;
			for (int i = 0; i < 3; i++)
			  {
				if (xAxis[i] == 3)
					if (map[x][3] == "  ")
						score = score + 1;
				if (map[x][3] == "* ")
					wasit = false;
			  }
			map[x][3] = "B>";
			for (int i = 1; i < 19; i++)
			  {
				map[i][1] = "  ";
			  }
			for (int i = 0; i < 20; i++)
			  {
				for (int j = 0; j < 30; j++)
				  {
					cout << map[i][j];
				  }
				cout << endl;
			  }
			cout << "Score = " << score;
            Sleep(96);
			system("cls");
		}
		cout << "Score = " << score << endl;
		if (highscore < score)
			highscore = score;
		cout << "Highscore= " << highscore << endl;
		cout << "restart?(y/n) = "; cin >> restart;
	}
	return 0;
}
