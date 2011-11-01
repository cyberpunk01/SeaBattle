/**
 * Copyright here
 */

/** @brief AIPlayer class 
 * @author igor
 */

//#ifndef AIPlayer
//#define AIPlayer

#include "Player.h"

namespace SeaBattle {


/** @class AIPlayer
 * @brief Class implements computer player logic */
class AIPlayer : public Player
               , public PlayerListener
{
public:
    AIPlayer();
    ~AIPlayer();
    
    /** @brief method to initialize player class */
    virtual void initialize();

    /** @brief generate coordinates according to player algorithm to shoot in
     * @param x - generated x coordinate
     * @param y - generated y coordinate */
    virtual void generateCoordinates(char &x, char &y);

    /** @brief coordinates and shoot result (PlayerListener callback)
     * @param x      - x coordinate
     * @param y      - y coordinate
     * @param result - shoot result */
    void shootResult(unsigned char x, unsigned char y, BattleFieldCell::CellState result);

    /** @brief indicate if ship was destroyed after last shoot (PlayerListener callback) */
    void shipWasDestroyed();

    /** @brief reset all class direction flags to false */
    void resetAllFlags();

    /// todo delete this function
    void redrawField() {}

/*
    void setHitFlag   (bool flag) { hitFlag   = flag; }
    void setTurnOn180 (bool flag) { turnOn180 = flag; }
    void setTurnOn90  (bool flag) { turnOn90  = flag; }
*/

protected:
    /** @brief setting random initial direction of move while shooting */
    void randomDirection();

private:
    bool hitFlag;
    bool turnOn180;
    bool turnOn90;

    char dx;
    char dy;

    char hitedX;
    char hitedY;

    char firstHitPosX;
    char firstHitPosY;
};
};

//#endif // AIPlayer
