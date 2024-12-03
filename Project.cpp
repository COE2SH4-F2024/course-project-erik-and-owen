#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *gameMechs;
Player *player;
Food *food;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while (!gameMechs->getExitFlagStatus()) // While the player has not lost so loseFlag is false
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

    gameMechs = new GameMechs(30, 15); // Instantiate with board dimensions
    food = new Food();
    player = new Player(gameMechs, food);

    gameMechs->createBoard(); // Function that creates the board on the heap
    food->generateFood(*player->getPlayerPos(), gameMechs->getBoardSizeX(), gameMechs->getBoardSizeY()); // Random starting position for the food
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        gameMechs->setInput(MacUILib_getChar()); // Get user input if there is some
    }
   
}

void RunLogic(void)
{
    if (gameMechs->getInput() != 0) { 
        switch(gameMechs->getInput()) {
            case ' ':
                gameMechs->setExitTrue();
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
                gameMechs->getBoard()[i][j] = '#'; // Set symbol to # if i is the top or bottom, or if j is the left or right of the board
            } else {
                gameMechs->getBoard()[i][j] = ' '; // Default board symbol to a space
            }

            for (int k = 0; k < player->getPlayerPos()->getSize(); k++) { // Loop through each body segment in the array list
                if(i == player->getPlayerPos()->getElement(k).pos->y && j == player->getPlayerPos()->getElement(k).pos->x) {
                    gameMechs->getBoard()[i][j] = player->getPlayerPos()->getElement(k).symbol; // If the board coordinates are the same as a the current body segments coordinates, set that position to the player symbol
                }
            }

            if (i == food->getFood()->pos->y && j == food->getFood()->pos->x) {
                gameMechs->getBoard()[i][j] = food->getSymbol();
            }

            MacUILib_printf("%c", gameMechs->getBoard()[i][j]); // Print whatever the symbol determined above is
        }

        MacUILib_printf("\n");
    }

    MacUILib_printf("Score %d\n", gameMechs->getScore());
    if(gameMechs->getLoseFlagStatus()) {
        MacUILib_printf("%s\n", gameMechs->getLoseMessage().c_str());
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    // MacUILib_clearScreen();    
    MacUILib_uninit();
    delete player;
    delete gameMechs;
    delete food;
}
