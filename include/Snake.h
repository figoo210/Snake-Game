#ifndef SNAKE_H
#define SNAKE_H

#include <Map.h>


class Snake : public Map
{
    public:
        Snake();


    private:
        int Tail;
        int SX;
        int SY;

};

#endif // SNAKE_H
