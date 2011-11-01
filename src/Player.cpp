/**
* Copyright here
*/

/**  Player class 
* @author igor
*/

#include "Player.h"


namespace SeaBattle { 

Player::Player()
: listener (NULL)
{
}

Player::~Player()
{
}

//todo implement different schemas of initializing and player logic
void Player::initialize()
{
    m_Field.fillFieldRandomly();
}

BattleFieldCell::CellState Player::shoot(unsigned char x, unsigned char y)
{
    BattleFieldCell::CellState result (m_Field.shootToCell(x, y));

    if (listener)
    {
        listener->shootResult(x, y, result);

        if (m_Field.shipDestroyed())
            listener->shipWasDestroyed();
    }

    return result;
}

void Player::setListener(PlayerListener *playerListener)
{
    listener = playerListener;
}

bool Player::hasShips() const
{
    return m_Field.hasShips();
}

//bool Player::shipDestroyed() const
//{
//    return m_Field.shipDestroyed(); 
//}

void Player::redrawField()
{
    return m_Field.print();
}

//todo create array not on stack
int* Player::getFieldArray()
{
    unsigned int i, j;
    int* k;
    int a[100];
    for(i = 0; i < 10; ++i)
		for(j = 0; j < 10; ++j)
            a[j+i] = (int)(m_Field.getFieldCell(j, i)->getCellState());
    
    /// NB!!!! its very very bad solution !!! redo asap
    k = a;
    return k;
}
};
