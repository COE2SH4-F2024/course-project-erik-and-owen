#include "GameMechs.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    loseFlag = false;
    score = 1;
    boardSizeX = 30;
    boardSizeY = 15;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false;
    loseFlag = false;
    score = 1;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
}

// do you need a destructor? 
// We do because we made the game board a double pointer array that needs to be deleted
GameMechs::~GameMechs()
{
    for(int i = 0; i < boardSizeY; i++) {
        delete[] board[i];
    }
    delete[] board;
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
   loseFlag = true; 
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here
void GameMechs::createBoard() { // Creates the board as a 2D array of pointers on the heap
    board = new char*[boardSizeY];
    for(int i = 0; i < boardSizeY; i++) {
        board[i] = new char[boardSizeX];
    }
}

char** GameMechs::getBoard() {
    return board;
}

string GameMechs::getLoseMessage() {
    return "You collided with yourself, you lose"; 
}
