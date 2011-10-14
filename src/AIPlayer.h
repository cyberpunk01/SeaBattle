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
{
public:
    AIPlayer();
    ~AIPlayer();
    
    virtual void initialize();

    virtual void generateCoordinates(unsigned char &x, unsigned char &y) const;
private:
};
};

//#endif // AIPlayer
