/**
* Copyright here
*/

/**  HumanPlayer class 
* @author igor
*/

///FIXME: what is the problem with defines?
//#ifndef HumanPlayer
//#define HumanPlayer

#include "Player.h"

namespace SeaBattle {

/*** HumanPlayer ***/
class HumanPlayer : public Player
{
public:
    HumanPlayer();
    virtual ~HumanPlayer();
    
    virtual void initialize();

    virtual void generateCoordinates(unsigned char &x, unsigned char &y) const;
private:
};
};
//#endif // HumanPlayer
