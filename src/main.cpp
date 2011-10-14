#include <stdio.h>
#include "Ship.h"
#include "BattleField.h"

using namespace SeaBattle;

int main()
{
unsigned char size = 3;
SeaBattle::Ship ship(size);
SeaBattle::BattleField field1;
SeaBattle::BattleField field2;

field1.fillFieldRandomly();
field2.fillFieldRandomly();

int x;
int y;
BattleFieldCell::CellState res = BattleFieldCell::S_NONE;

/// main game cycle
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
}

return 0;
}
