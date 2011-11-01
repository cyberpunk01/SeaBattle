/**
 * Copyright here
 */

/** @brief HumanPlayer class 
 * @author igor
 */

// FIXME: what is the problem with defines?
// #ifndef HumanPlayer
// #define HumanPlayer

#include "Player.h"

namespace SeaBattle {

/** @class HumanPlayer
 * @brief Implements human player */
class HumanPlayer : public Player
{
public:
    HumanPlayer();
    virtual ~HumanPlayer();
    
    /** @brief method to initialize player class */
    virtual void initialize();

    /** @brief generate coordinates according to player algorithm to shoot in
     * @param x - generated x coordinate
     * @param y - generated y coordinate */
    virtual void generateCoordinates(char &x, char &y);

private:

};
};

//#endif // HumanPlayer
