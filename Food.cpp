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

void Food::generateFood(const objPosArrayList &blockOff, const int xRange, const int yRange) {
        int candidateX, candidateY;

        for (int i = 0; i < blockOff.getSize(); i++) { // loop through the snake body
            do {
                candidateX = rand() % (xRange - 2) + 1; 
                candidateY = rand() % (yRange - 2) + 1;
            } while (candidateX == blockOff.getElement(i).pos->x && candidateY == blockOff.getElement(i).pos->y); // loop again if the food overlaps part of the player
        }


        foodPos->setObjPos(candidateX, candidateY, blockOff.getHeadElement().getSymbol());
}

objPos* Food::getFood() const {
    return foodPos;
}

char Food::getSymbol() const {
    return symbol;
}