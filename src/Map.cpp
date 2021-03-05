#include "Map.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

Map::Map()
{

}

void Map::Setup()
{
    //Player
    score = 0;
    lose = false;
    //Snake
    SX = MX/2;
    SY = MY/2;
    Tail = 0;
}

void Map::generate_Food()
{
    srand(time(NULL));
    foodX = rand() % (MX-2)+1;
    foodY = rand() % (MY-2)+1;
}

void Map::Draw()
{
    for(int i=0; i<MY; i++)
    {
        for(int j=0; j<MX; j++)
        {
            if(i == 0 || i == MY-1) cout<< "*";
            else if(j == 0 || j == MX-1) cout<< "*";
            else if(i == foodY && j == foodX) cout<< "F";
            else if(i == SY && j == SX) cout<< "O";
            else
                cout << " ";
        }
        cout <<endl;
    }
}
