#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

// Assuming objPos is already defined, if not, include it here
#include "objPos.h"  // Adjust the include path if necessary

// SnakeFood Class to handle food generation and storage
class SnakeFood {
private:
    objPos foodPos;  // Stores the current food position

public:
    // Constructor
    SnakeFood();

    // Generate a new food position randomly, avoiding the given blockOff position
    void generateFood(objPos blockOff);

    // Getter method to retrieve the current food position
    objPos getFoodPos() const;

    // For debugging or visualization, print the food's position
    void printFoodPos() const;
};

#endif // SNAKEFOOD_H