#ifndef MAP_H
#define MAP_H


class Map
{
    public:
        Map();
        void Setup();
        void generate_Food();
        void Draw();
friend class Snake;
    protected:
        const int MX = 40;
        const int MY = 20;
        int foodX;
        int foodY;
        int Tail;
        int SX;
        int SY;
        int score;
        bool lose;
};

#endif // MAP_H
