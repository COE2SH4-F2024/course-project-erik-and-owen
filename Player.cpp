#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFoodRef;
    myDir = STOP;

    // playerPos.setObjPos(5, 3, '*');
    objPos head = {5, 3, '*'};
    // objPos middle = {5, 4, '*'};
    // objPos middle2 = {5, 5, '*'};
    // objPos middle3 = {5, 6, '*'};
    // objPos middle4 = {5, 7, '*'};
    // objPos middle5 = {5, 8, '*'};
    // objPos middle6 = {5, 9, '*'};
    // objPos tail = {5, 10, '*'};
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(head);
    // playerPosList->insertTail(middle);
    // playerPosList->insertTail(middle2);
    // playerPosList->insertTail(middle3);
    // playerPosList->insertTail(middle4);
    // playerPosList->insertTail(middle5);
    // playerPosList->insertTail(middle6);
    // playerPosList->insertTail(tail);

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    if (mainGameMechsRef) {
        delete mainGameMechsRef;
    }

    if (mainFoodRef) {
        delete mainFoodRef;
    }

    if (playerPosList) {
        delete playerPosList;
    }
}

objPosArrayList* Player::getPlayerPos() const {
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic          
        if (mainGameMechsRef->getInput() != 0) { // Only run if an input has been given
            switch(mainGameMechsRef->getInput()) { // Check the input
                case 'w':
                    if (myDir != DOWN) { // Each direction change only happens if the opposite direction is not the current direction
                        myDir = UP;
                    }
                    break;
                case 's':
                    if (myDir != UP) {
                        myDir = DOWN;
                    }
                    break;
                case 'd':
                    if (myDir != LEFT) {
                        myDir = RIGHT;
                    }
                    break;
                case 'a':
                    if (myDir != RIGHT) {
                        myDir = LEFT;
                    }
                    break;
            }
            mainGameMechsRef->clearInput(); // Clear input to ensure new input can be excepted
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos temp; // temporary position object to eventually instantiate an array list element with

    switch(myDir) {
        case UP:
            // Create a new position that has the same coordinates as the current head of the list, except one space higher in the y direction
            temp.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y - 1, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->y == 0) { // Wrap around condition to change the y positioning if needed
                temp.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;
        case DOWN: // The rest of the directions work the same as up
            temp.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y + 1, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->y == mainGameMechsRef->getBoardSizeY() - 1) {
                temp.pos->y = 1;
            }
            break;
        case RIGHT:
            temp.setObjPos(playerPosList->getHeadElement().pos->x + 1, playerPosList->getHeadElement().pos->y, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->x == mainGameMechsRef->getBoardSizeX() - 1) {
                temp.pos->x = 1;
            }
            break;
        case LEFT:
            temp.setObjPos(playerPosList->getHeadElement().pos->x - 1, playerPosList->getHeadElement().pos->y, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->x == 0) {
                temp.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;
    }

    if (checkFoodConsumption()) {
        playerPosList->insertHead(temp); // Make the temporary position the current head once the temporary position has the correct move instrucstions
        mainFoodRef->generateFood(*playerPosList, mainGameMechsRef->getBoardSizeX(), mainGameMechsRef->getBoardSizeY());
    } else {
        if (myDir != STOP) {
            playerPosList->insertHead(temp); // Make the temporary position the current head once the temporary position has the correct move instrucstions
            playerPosList->removeTail(); // Remove the last element to simulate movement

        }
    }

    // Checking for collision with itself
    for (int i = 0; i < playerPosList->getSize(); i++) { // Loop through each body segment
        for (int j = i + 1; j < playerPosList->getSize(); j++) { // Loop through each body segment, starting one index higher than the outer loop to allow coordinate comparison
            const objPos& pos1 = playerPosList->getElement(i).getObjPos(); // current positions of the two indexes about to be compared
            const objPos& pos2 = playerPosList->getElement(j).getObjPos();
            if (pos1.isPosEqual(&pos2)) { // Check if the two positions are the same
                mainGameMechsRef->setLoseMessage(1); // Choose the collision with yourself error message
                mainGameMechsRef->setLoseFlag(); 
                mainGameMechsRef->setExitTrue();
                return; // No need to loop through the rest of the indexes if a collision is detected
            }
        }
    } 
}

// More methods to be added

bool Player::checkFoodConsumption() {
    bool consumedFood = false;
    for (int i = 0; i < playerPosList->getSize(); i++) {
        const objPos& playerPos = playerPosList->getElement(i).getObjPos();
        const objPos& foodPos = mainFoodRef->getFood()->getObjPos();
        if (playerPos.isPosEqual(&foodPos)) {
            consumedFood = true;
        }
    }

    return consumedFood;
}