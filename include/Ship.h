/**
 * Copyright here
 */

/** @brief Ship class
 * @author igor
 */

#ifndef SHIP
#define SHIP

#include <vector>

namespace SeaBattle {

/** @class Ship 
 * @brief Implements ship in the game */
class Ship
{
public:
    Ship();
    ~Ship();

    /** @brief constructor
     * @param size - deck count */
    Ship(unsigned char size);

    /** @brief Set next deck as destroyed 
     * @retval true  - ship killed
     * @retval false - deck is destroyed and ship doesn't killed */
    bool destroyDeck();

    /** @brief get ship size
     * @return ship size */
    unsigned char getSize() const { return m_Size; };

// todo delete vector of decks - change it for count of decks with is not destroyed
private:
    unsigned char              m_Size;
    std::vector<unsigned char> m_Decks;        
};
};

#endif // SHIP
