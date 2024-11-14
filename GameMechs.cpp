#include "GameMechs.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
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