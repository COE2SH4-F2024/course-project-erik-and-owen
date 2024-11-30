#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // playerPos.setObjPos(5, 3, '*');
    objPos head = {5, 3, '*'};
    objPos middle = {5, 4, '*'};
    objPos middle2 = {5, 5, '*'};
    objPos middle3 = {5, 6, '*'};
    objPos tail = {5, 7, '*'};
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(head);
    playerPosList->insertTail(middle);
    playerPosList->insertTail(middle2);
    playerPosList->insertTail(middle3);
    playerPosList->insertTail(tail);

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    if (mainGameMechsRef) {
        delete mainGameMechsRef;
    }

    if (playerPosList) {
        delete playerPosList;
    }
}

// objPos Player::getPlayerPos() const
// {
    // return the reference to the playerPos arrray list
    // return playerPos;
// }

objPosArrayList* Player::getPlayerPos() const {
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic          
        if (mainGameMechsRef->getInput() != 0) {
            switch(mainGameMechsRef->getInput()) {
                case 'w':
                    if (myDir != DOWN) {
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
            mainGameMechsRef->clearInput();
        }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos temp;
    switch(myDir) {
        case UP:
            temp.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y - 1, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->y == 0) {
                temp.pos->y = mainGameMechsRef->getBoardSizeY() - 2;

            }
            playerPosList->insertHead(temp);
            playerPosList->removeTail();
            break;
        case DOWN:
            temp.setObjPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y + 1, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->y == mainGameMechsRef->getBoardSizeY() - 1) {
                temp.pos->y = 1;
            }
            playerPosList->insertHead(temp);
            playerPosList->removeTail();
            break;
        case RIGHT:
            temp.setObjPos(playerPosList->getHeadElement().pos->x + 1, playerPosList->getHeadElement().pos->y, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->x == mainGameMechsRef->getBoardSizeX() - 1) {
                temp.pos->x = 1;
            }
            playerPosList->insertHead(temp);
            playerPosList->removeTail();
            break;
        case LEFT:
            temp.setObjPos(playerPosList->getHeadElement().pos->x - 1, playerPosList->getHeadElement().pos->y, playerPosList->getHeadElement().getSymbol());
            if (temp.pos->x == 0) {
                temp.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            }
            playerPosList->insertHead(temp);
            playerPosList->removeTail();
            break;
    }
}

// More methods to be added