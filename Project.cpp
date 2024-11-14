#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *gameMechs;
Player *player;

string DEBUG_MESSAGE;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    // while(exitFlag == false)  
    while (!gameMechs->getExitFlagStatus())
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    gameMechs = new GameMechs(30, 15);
    player = new Player(gameMechs);

    gameMechs->createBoard();
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        gameMechs->setInput(MacUILib_getChar());
    }
   
}

void RunLogic(void)
{
    if (gameMechs->getInput() != 0) {
        switch(gameMechs->getInput()) {
            case ' ':
                gameMechs->setExitTrue();
                break;
            case 'l':
                gameMechs->incrementScore();
                break;
            case '1':
                gameMechs->setLoseFlag();
                DEBUG_MESSAGE = gameMechs->loseMessage(1);
                break;
            case '2':
                gameMechs->setLoseFlag();
                DEBUG_MESSAGE = gameMechs->loseMessage(2);
                break;
            case '3':
                gameMechs->setLoseFlag();
                DEBUG_MESSAGE = gameMechs->loseMessage(3);
                break;
        }
    }

    player->updatePlayerDir();
    player->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    for (int i = 0; i < gameMechs->getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs->getBoardSizeX(); j++) {
            if (i == 0 || i == gameMechs->getBoardSizeY() - 1 || j == 0 || j == gameMechs->getBoardSizeX() - 1) {
                gameMechs->getBoard()[i][j] = '#';
            } else if (i == player->getPlayerPos().pos->y && j == player->getPlayerPos().pos->x) {
                gameMechs->getBoard()[i][j] = player->getPlayerPos().symbol;
            } else {
                gameMechs->getBoard()[i][j] = ' ';
            }

            MacUILib_printf("%c", gameMechs->getBoard()[i][j]);
        }

        MacUILib_printf("\n");
    }

    MacUILib_printf("Score %d\n", gameMechs->getScore());
    if(gameMechs->getLoseFlagStatus()) {
        MacUILib_printf("%s\n", DEBUG_MESSAGE.c_str());
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
