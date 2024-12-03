#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food {
    private:
        objPos *foodPos;
        char symbol;

    public:
        Food();
        ~Food();

        void generateFood(const objPosArrayList &blockOff, const int xRange, const int yRange);
        objPos* getFood() const;
        char getSymbol() const;
};

#endif