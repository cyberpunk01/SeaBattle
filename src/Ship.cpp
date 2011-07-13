/**
* Copyright here
*/

/**  Ship class 
* @author igor
*/

#include "Ship.h"

namespace SeaBattle { 
Ship::Ship()
{
}

Ship::Ship(unsigned char size)
{
    m_Size = size;
    unsigned char i = 0;

    // set all decks as normal
    m_Decks.clear();
    for (; i < m_Size; ++i)
	m_Decks.push_back(0);
}

Ship::~Ship()
{

}

bool Ship::destroyDeck(unsigned char i)
{
    bool res = false;

    if (m_Size > i)
    {
	m_Decks.at(i) = 1;
        res = true;
    }

    return res;
}
};
