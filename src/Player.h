/**
* Copyright here
*/

/**  Player class 
* @author igor
*/

#ifndef PLAYER
#define PLAYER

#include "BattleField.h"

namespace SeaBattle {

/*** Player ***/
class Player
{
public:
    Player();
    virtual ~Player();
    
    /* beginning initializing of the player */
    virtual void initialize() = 0;

    /* shoot into player's field  */
    virtual BattleFieldCell::CellState shoot(unsigned char x, unsigned char y);

    // different implementation for different players and platforms
    /* algorithm of choose coordinates to shoot in */
    virtual void generateCoordinates(unsigned char &x, unsigned char &y) const = 0;

    /* indicates that the player have unbroken ships */
    virtual bool hasShips() const;

    /* draw player field */
    virtual void redrawField();

private:
    BattleField m_Field;
};
};

#endif // PLAYER
