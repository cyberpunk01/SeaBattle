/**
* Copyright here
*/

/**  Player class 
* @author igor
*/

#include "Player.h"

namespace SeaBattle { 

Player::Player()
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
    return m_Field.shootToCell(x, y);
}

bool Player::hasShips() const
{
    return m_Field.hasShips();
}

void Player::redrawField()
{
    return m_Field.print();
}
};
