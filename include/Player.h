/**
 * Copyright here
 */

/** @brief Player and PlayerListener class 
 * @author igor
 */

#ifndef PLAYER
#define PLAYER

#include "BattleField.h"

namespace SeaBattle {

/** @class PlayerListener 
 * @brief Notify other player about his shoot result */
class PlayerListener
{
public:
    PlayerListener() {};
    virtual ~PlayerListener() {};

    /** @brief coordinates and shoot result (PlayerListener callback)
     * @param x      - x coordinate
     * @param y      - y coordinate
     * @param result - shoot result */
    virtual void shootResult(unsigned char x, unsigned char y, BattleFieldCell::CellState result) = 0;

    /** @brief indicate if ship was destroyed after last shoot (PlayerListener callback) */
    virtual void shipWasDestroyed() = 0;
};


/** @class Player
 * @brief Interface class for player in game */
class Player //: public PlayerListener
{
public:
    Player();
    virtual ~Player();
    
    /** @brief beginning initializing of the player */
    virtual void initialize() = 0;

    /** @brief shoot into player's field  
     * @param x - x coordinate
     * @param y - y coordinate 
     * @return previous cell state */
    virtual BattleFieldCell::CellState shoot(unsigned char x, unsigned char y);

    /** @brief algorithm of choose coordinates to shoot in
     * Generate coordinates according to player algorithm to shoot in.
     * Different implementation for different players and platforms
     * @param x - generated x coordinate
     * @param y - generated y coordinate */
    virtual void generateCoordinates(char &x, char &y) = 0;

    /** @brief set listener for player 
     * @param playerListener - player listener */
    virtual void setListener(PlayerListener *playerListener);

    /** @brief indicates that the player have unbroken ships
     * @retval true  - field has undefeated ships
     * @retval false - hasn't */
    virtual bool hasShips() const;

    /* @brief indicates that the player ship was destroyed */
//    virtual bool shipDestroyed() const;

    /** @brief draw player field */
    virtual void redrawField();
    
    /* return field array */
    virtual int* getFieldArray();

private:
    BattleField    m_Field;
    PlayerListener *listener;
};
};

#endif // PLAYER
