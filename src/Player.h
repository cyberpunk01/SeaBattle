/**
* Copyright here
*/

/**  Player and PlayerListener class 
* @author igor
*/

#ifndef PLAYER
#define PLAYER

#include "BattleField.h"

namespace SeaBattle {

/*** Player Listener ***/
class PlayerListener
{
public:
    PlayerListener() {};
    virtual ~PlayerListener() {};

    virtual void shootResult(unsigned char x, unsigned char y, BattleFieldCell::CellState result) = 0;

    virtual void shipWasDestroyed() = 0;
};


/*** Player ***/
class Player //: public PlayerListener
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
    virtual void generateCoordinates(int &x, int &y) = 0;

    /* set listener for player */
    virtual void setListener(PlayerListener *playerListener);

    /* indicates that the player have unbroken ships */
    virtual bool hasShips() const;

    /* indicates that the player ship was destroyed */
//    virtual bool shipDestroyed() const;

    /* draw player field */
    virtual void redrawField();

private:
    BattleField    m_Field;
    PlayerListener *listener;
};
};

#endif // PLAYER
