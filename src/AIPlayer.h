/**
* Copyright here
*/

/**  AIPlayer class 
* @author igor
*/

//#ifndef AIPlayer
//#define AIPlayer

#include "Player.h"

namespace SeaBattle {

/*** AIPlayer ***/
class AIPlayer : public Player
               , public PlayerListener
{
public:
    AIPlayer();
    ~AIPlayer();
    
    virtual void initialize();

    virtual void generateCoordinates(int &x, int &y);

    void shootResult(unsigned char x, unsigned char y, BattleFieldCell::CellState result);

    void shipWasDestroyed();

    /* reset all class direction flags to false */
    void resetAllFlags();

    // todo delete this func 
    void redrawField() {}

/*
    void setHitFlag   (bool flag) { hitFlag   = flag; }
    void setTurnOn180 (bool flag) { turnOn180 = flag; }
    void setTurnOn90  (bool flag) { turnOn90  = flag; }
*/

protected:
    /* settting random initial direction of move */
    void randomDirection();

private:
    bool hitFlag;
    bool turnOn180;
    bool turnOn90;

    int  dx;
    int  dy;

    int hitedX;
    int hitedY;

    int firstHitPosX;
    int firstHitPosY;
};
};

//#endif // AIPlayer
