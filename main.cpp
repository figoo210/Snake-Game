#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int score;
bool Lose;
const int MX = 40, MY = 20;
int SY, SX, Tail, foodX, foodY;
enum Direction {Top = 1, Right, Left, Down};
Direction put;

/* to make a tail for snake
every point from the tail has an own location
so to give for every point location
we need to make an array
one will be array for X and one for Y
to make our location for every point
let's see
*/
int Tail_array_X[50], Tail_array_Y[50];
void shift_Tail(int sht[50], int n=50)
{
    for(int i=n-2; i>=0; i--)
    {
        sht[i+1] = sht[i];
    }
}

void generate_Food()
{
    srand(time(NULL));
    foodX = rand() % (MX-2)+1;
    foodY = rand() % (MY-2)+1;
}

void Setup()
{
    generate_Food();
    //Player
    score = 0;
    Lose = false;
    //Snake
    SX = MX/2;
    SY = MY/2;
    Tail = 0;
}


void Draw()
{
    system("cls");
    for(int i=0; i<MY; i++)
    {
        for(int j=0; j<MX; j++)
        {
            if(i == 0 || i == MY-1) cout<< "*";
            else if(j == 0 || j == MX-1) cout<< "*";
            else if(i == foodY && j == foodX) cout<< "F";
            else if(i == SY && j == SX) cout<< "O";
            else
            {
                bool done;
                for(int z=0; z<Tail; z++)
                {
                    if(Tail_array_X[z] == Tail_array_Y[z] == i)
                    {
                        done = true;
                        cout<< "o";
                        break;
                    }
                }
                if(!done) cout << " ";
            }
        }
        cout <<endl;
    }
    cout << "Score = " << score << endl;

}

void Inputing()
{
    if(_kbhit())
    {
        char c;
        c = _getch();
        switch(c)
        {
        case 'w':
            put = Top;
            break;
        case 'd':
            put = Right;
            break;
        case 'a':
            put = Left;
            break;
        case 's':
            put = Down;
            break;
        case 'o':
            exit(0);
            break;
        default:
            break;
        }
    }
}

void Moving()
{
    shift_Tail(Tail_array_X, 50);
    shift_Tail(Tail_array_Y, 50);
    Tail_array_X[0] = SX;
    Tail_array_Y[0] = SY;
    switch(put)
    {
    case Top:
        SY--;
        break;
    case Down:
        SY++;
        break;
    case Right:
        SX++;
        break;
    case Left:
        SX--;
        break;
    default:
        break;
    }

    if(SY >= MY || SX >= MX || SY <= 0 || SX <= 0)
    {
        Lose = true;
    }
    if(SY == foodY && SX == foodX)
    {
        generate_Food();
        score += 5;
    }
}

int main()
{
    Setup();
   while (!Lose)
   {
       Draw();
       Inputing();
       Moving();
       Sleep(20);
   }

    system("pause");
}
