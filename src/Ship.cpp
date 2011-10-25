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

//todo rewrite method without vector using
bool Ship::destroyDeck()
{
	//suggest that ship is killed
	bool res = true;

    // destroy next deck
	unsigned char j = 0;
    for (; j < m_Size; ++j)
    {
        if (m_Decks.at(j) == 0)
        {
    		m_Decks.at(j) = 1;
            break;
        }
    }

	//check our suggestion that ship is killed
	for (j = 0; j < m_Size; ++j)
		if (m_Decks.at(j) != 1)
			res = false;

	return res;
}
};
