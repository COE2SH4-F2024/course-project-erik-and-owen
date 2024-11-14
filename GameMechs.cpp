#include "GameMechs.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
}

// do you need a destructor?
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

}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

void GameMechs::createBoard() {
    board = new char*[boardSizeY];
    for(int i = 0; i < boardSizeY; i++) {
        board[i] = new char[boardSizeX];
    }
}

char** GameMechs::getBoard() {
    return board;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    
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