#include <stdio.h>
#include "Ship.h"
#include "BattleField.h"

int main()
{
unsigned char size = 3;
SeaBattle::Ship ship(size);
SeaBattle::BattleField field;

printf("\nBEGIN.\n");

field.print();

printf("\nEND.\n");

return 0;
}
