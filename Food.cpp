#include<stdlib.h>
#include <time.h>

#include "Food.h"

Food::Food() {
    foodPos = new objPos();
    symbol = '$';
    foodPos->setObjPos(8, 8, symbol);
    srand(time(NULL));

}

Food::~Food() {
    if (foodPos) {
        delete foodPos;
    }
}

void Food::generateFood(objPos blockOff, const int xRange, const int yRange) {
        int candidateX, candidateY;

        do {
            candidateX = rand() % (xRange - 2) + 1;
            candidateY = rand() % (yRange - 2) + 1;
        } while (candidateX == blockOff.pos->x && candidateY == blockOff.pos->y);

        foodPos->setObjPos(candidateX, candidateY, blockOff.getSymbol());
}

objPos* Food::getFood() const {
    return foodPos;
}

char Food::getSymbol() const {
    return symbol;
}