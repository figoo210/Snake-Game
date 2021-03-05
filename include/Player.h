#ifndef PLAYER_H
#define PLAYER_H

#include <Map.h>


class Player : public Map
{
    public:
        Player();

    private:
        int score;
        bool lose;
};

#endif // PLAYER_H
