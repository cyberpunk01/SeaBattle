/**
* Copyright here
*/

/**  Ship class 
* @author igor
*/

#ifndef SHIP
#define SHIP

#include <vector>

namespace SeaBattle {
class Ship
{
public:
    Ship();
    Ship(unsigned char size); // deck count
    ~Ship();

    /* Check 'i' deck as destroyed 
     * \param i - 0 - is normal deck state
     *            1 - deck is destroyed
     * \return 1 - ship killed
     * \return 0 - deck is destroyed/ship doesn't killed
     */
    bool destroyDeck(unsigned char i);

private:
    unsigned char              m_Size;
    std::vector<unsigned char> m_Decks;        
};
};

#endif // SHIP
