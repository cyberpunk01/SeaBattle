#include <stdio.h>
#include "Ship.h"
#include "BattleField.h"

int main()
{
unsigned char size = 3;
SeaBattle::Ship ship(size);
SeaBattle::BattleField field;

printf("\nBEGIN.\n");

field.fillFieldRandomly();
field.print();

printf("END.\n");

return 0;
}
