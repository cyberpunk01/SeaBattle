/**
* Copyright here
*/

/**  BattleField class 
* @author igor
*/

#include "BattleField.h"

namespace SeaBattle
{

/*** BattleFieldCell ***/
BattleFieldCell::BattleFieldCell()
: m_State (BattleFieldCell::S_NONE),
  m_Ship (NULL)
{
}

BattleFieldCell::~BattleFieldCell()
{
}

/*** BattleField ***/
BattleField::BattleField()
{
unsigned int i = 0, 
             j = 0;

for(; i < 4; ++i)
{
    m_Sips[i] = 0;
}

for( i = 0; i < 10; ++i)
{
    for(; j < 10; ++j)
    {
        m_Field[i][j] = NULL;
    }
}
}

BattleField::~BattleField()
{
}

bool BattleField::ShootToCell(unsigned char i, unsigned char j)
{

}

bool BattleField::PutShip(unsigned char i, unsigned char j, unsigned char d, unsigned char n)
{

}

} //namespace
