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
        listener->shootResult(x, y, result);

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

bool Player::shipDestroyed() const
{
    return m_Field.shipDestroyed(); 
}

void Player::redrawField()
{
    return m_Field.print();
}
};
