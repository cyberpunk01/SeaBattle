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

/*** Ship ***/
class Ship
{
public:
    Ship();
    Ship(unsigned char size); // deck count
    ~Ship();

    /** Check 'i' deck as destroyed 
     * @return: 1 - ship killed
     *         0 - deck is destroyed/ship doesn't killed
     */
    bool destroyDeck();

    // return ship size
    unsigned char getSize() const { return m_Size; };

//todo delete vector of decks - change it for count of decks with is not destroyed
private:
    unsigned char              m_Size;
    std::vector<unsigned char> m_Decks;        
};
};

#endif // SHIP
