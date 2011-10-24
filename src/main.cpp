#include <stdio.h>
#include "Ship.h"
#include "BattleField.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

using namespace SeaBattle;

int main()
{
//SeaBattle::BattleField field1;
//SeaBattle::BattleField field2;

//field1.fillFieldRandomly();
//field2.fillFieldRandomly();

AIPlayer*    aiPlayer (new AIPlayer());
HumanPlayer* hPlayer  (new HumanPlayer());

hPlayer->setListener(aiPlayer);

int x;
int y;
BattleFieldCell::CellState res = BattleFieldCell::S_NONE;

/// new main game cycle
while(true)
{
    /// first player main cycle
    do {
        aiPlayer->redrawField();
        if (aiPlayer->hasShips() == false)
        {
            printf("first pl won!!! \n");
            return 0;
        }
        printf("first pl turn: \n");
        
        hPlayer->generateCoordinates(x, y);

        res = aiPlayer->shoot(x, y);

        printf("result-%i\n", res);
    } while (res != BattleFieldCell::S_FREE);
//} while (0); //debug
    /// second player main cycle
    do {
        hPlayer->redrawField();
        if (hPlayer->hasShips() == false)
        {
            printf("second pl won!!! \n");
            return 0;
        }
        printf("second pl turn: \n");
        
        aiPlayer->generateCoordinates(x, y);

        res = hPlayer->shoot(x, y);
//        if (BattleFieldCell::S_DECK == res && hPlayer->shipDestroyed())
//            aiPlayer->resetAllFlags();

        printf("result-%i\n", res);
    } while (res != BattleFieldCell::S_FREE);
  
/// old main game cycle
/*
while(true)
{
    /// first player main cycle
    do {
        field2.print();
        if (field2.hasShips() == false)
        {
            printf("first pl won!!! \n");
            return 0;
        }
        printf("first pl turn: \n");

        do {
            printf("x: ");
            scanf("%i", &x);
        } while (x < 0 || x > 9);

        do {
            printf("y: ");
            scanf("%i", &y);
        } while (y < 0 || y > 9);

        res = field2.shootToCell(x, y);
        printf("result-%i\n", res);
    } while (res != BattleFieldCell::S_FREE);

    /// second player main cycle
    do {
        field1.print();
        if (field1.hasShips() == false)
        {
            printf("second pl won!!! \n");
            return 0;
        }
        printf("second pl turn: \n");

        do {
            printf("x: ");
            scanf("%i", &x);
        } while (x < 0 || x > 9);

        do {
            printf("y: ");
            scanf("%i", &y);
        } while (y < 0 || y > 9);

        res = field1.shootToCell(x, y);
        printf("result-%i\n", res);
    } while (res != BattleFieldCell::S_FREE);
*/
}

return 0;
}
