#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class Food {
    private:
        objPos *foodPos;
        char symbol;

    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff, const int xRange, const int yRange);
        objPos* getFood() const;
        char getSymbol() const;
};

#endif