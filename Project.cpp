#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
#define NUM_ROWS 10
#define NUM_COlUMNS 20

GameMechs gameMechs;
Player *player;

char board[NUM_ROWS][NUM_COlUMNS];

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
    while (!gameMechs.getExitFlagStatus())
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

    player = new Player(&gameMechs);
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        gameMechs.setInput(MacUILib_getChar());
    }
   
}

void RunLogic(void)
{
    if (gameMechs.getInput() != 0) {
        switch(gameMechs.getInput()) {
            case ' ':
            gameMechs.setExitTrue();
                break;
        }
    }

    player->updatePlayerDir();
    player->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    for (int i = 0; i < gameMechs.getBoardSizeY(); i++) {
        for (int j = 0; j < gameMechs.getBoardSizeX(); j++) {
            if (i == 0 || i == gameMechs.getBoardSizeY() - 1 || j == 0 || j == gameMechs.getBoardSizeX() - 1) {
                board[i][j] = '#';
            } else if (i == player->getPlayerPos().pos->y && j == player->getPlayerPos().pos->x) {
                board[i][j] = player->getPlayerPos().symbol;
            } else {
                board[i][j] = ' ';
            }

            MacUILib_printf("%c", board[i][j]);
        }

        MacUILib_printf("\n");
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
