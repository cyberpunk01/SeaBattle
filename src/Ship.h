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

    /* Check 'i' deck as destroyed */
    bool destroyDeck(unsigned char i);

private:
    unsigned char              m_Size;
    std::vector<unsigned char> m_Decks;        
};
};

#endif // SHIP
