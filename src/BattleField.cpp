/**
* Copyright here
*/

/**  BattleField class 
* @author igor
*/

#include "BattleField.h"
#include <stdio.h>

namespace SeaBattle
{

/*** BattleFieldCell ***/
BattleFieldCell::BattleFieldCell()
: m_State (BattleFieldCell::S_FREE),
  m_Ship (NULL)
{
}

BattleFieldCell::~BattleFieldCell()
{
}

/*** BattleField ***/
BattleField::BattleField()
{
unsigned int i = 0, j; 

for(; i < 4; ++i)
{
    m_Sips[i] = 0;
}

i = 0;
for(; i < 10; ++i)
{
j = 0;
    for(; j < 10; ++j)
    {
//        m_Field[i][j] = NULL;
        m_Field[i][j] = new BattleFieldCell();
        printf("%i ", m_Field[i][j]->m_State);
    }
printf(" |\n");
}
}

BattleField::~BattleField()
{
}

bool BattleField::shootToCell(unsigned char i, unsigned char j)
{

}

bool BattleField::putShip(unsigned char i, unsigned char j, unsigned char d, unsigned char n)
{

}

void BattleField::print()
{
unsigned int i = 0, j;

for(j = 0; i < 10; ++i)
{
j = 0;
    for(; j < 10; ++j)
    {
        printf("%i ", m_Field[i][j]->m_State);
    }
printf("|\n");
}
}

} //namespace
