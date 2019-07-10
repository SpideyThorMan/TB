
#include<iostream>
#include<windows.h>
#include<dos.h>
#include<time.h>
#include<conio.h>
#include<fstream>

using namespace std;
void delay(int milliseconds)
{
	clock_t start = clock();
	while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}
int L_PER_INCR = 2;





void game(int s){

    char restart ='y';
    srand(time(0));//to make the program randomize
	char mv;
	int highscore = 0;
	//keep while
	ini:
	if (restart == 'y')
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
		string map[100][100];
		for (int i = 0; i < 100; i++)
		  {
			for (int j = 0; j < 100; j++)
			   {
				if (i == 0 || i == 19 || j == 29 || j == 0)
					map[i][j] = " #";
				else
					map[i][j] = " ";
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
				    {
					if (map[x][3] == "  ")
						score = score + 1;
				    }
				if (map[x][3] == "* ")
				    {
					wasit = false;
				    }

				if (map[x][3] == " #")
				    {
					wasit = false;
				    }
			  }
			map[x][3] = "B>";
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

             cout << "\t\t\t\nScore = " << score;

             Sleep(s);

			system("cls");
		}



        cout << "Score = " << score << endl;

		if (highscore < score)
			highscore = score;

		cout << "Highscore= " << highscore << endl;

         system("color 04");

        cout<<"Press Y to countinue and any key to exit"<<endl;
        cin>>restart;

	}
	 if(restart == 'n')
       {
           system("color 05");
            cout<<"thank you for playing"<<endl;

           system("pause");
       }
       else if(restart=='y') {
        goto ini;
       }
       else{
            system("cls");
        system("color 05");
            cout<<"thank you for playing"<<endl;
            system("pause");
       }
}




void easy(){
    int s=300;
    game(s);

}

void medium(){
int s=200;
    game(s);

}

void hard(){
int s=150;
    game(s);

}

void veryhard(){
int s=90;
    game(s);

}


//dont do any thing below it:
int main(){

    int k;
    ini:
    system("color 5e");
    char restart='y';

		system("cls");
		cout << "\n";
		cout << "\t\t\t\tPLease wait game is loding: \n\n\n \t\t\t it might take few second"<<endl<<endl;
		for (int j = 0; j <100 /*i / L_PER_INCR*/; j++){
			cout<<char(990);
			Sleep(10);
		delay(1 / L_PER_INCR);
		}

           system("color 6");
            system("cls");
    		cout <<endl<< "\n\n\n\t\t\t\t\t\tPress 'Y' to choose the level"<<endl;
            cin >>restart;

    if(restart=='y')
        {
            system("cls");
    int input;
    system("color e4");
    cout<<"-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~>\tLEVEL\t<-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~\n"<<endl;
    cout<<"\t\t\t\t-~-~-~-~-~-~-~-~-~-> 1. easy <-~-~-~-~-~-~-~-~-~-"<<endl;
    cout<<"\t\t\t\t-~-~-~-~-~-~-~-~-~-> 2. medium <-~-~-~-~-~-~-~-~-"<<endl;
    cout<<"\t\t\t\t-~-~-~-~-~-~-~-~-~-> 3. hard <-~-~-~-~-~-~-~-~-~-"<<endl;
    cout<<"\t\t\t\t-~-~-~-~-~-~-~-~-~-> 4. very hard <-~-~-~-~-~-~-~"<<endl;
    cin>>input;
    switch (input){
    case 1:
        //Sleep(300);

        easy();
        break;
    case 2:

        medium();
        break;
    case 3:

        hard();
        break;
    case 4:

        veryhard();
        break;
    }
}
    else{
            char exit;
            system("cls");
            cout<<"Are you sure you want to discontinue\n\n\t\t press Y to exit and any key to continue";
            cin>>exit;

        if(exit == 'y')
        {
            system("exit");


        }
        else{
                goto ini;
        }


    return 0;
    }}
