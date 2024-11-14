#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000
#define NUM_ROWS 10
#define NUM_COlUMNS 20

char board[NUM_ROWS][NUM_COlUMNS];

bool exitFlag;
char input;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar()) {
        input = MacUILib_getChar();
    }
   
}

void RunLogic(void)
{
    switch(input) {
        case ' ':
            exitFlag = true;
            break;
    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COlUMNS; j++) {
            if (i == 0 || i == NUM_ROWS - 1 || j == 0 || j == NUM_COlUMNS - 1) {
                board[i][j] = '#';
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
