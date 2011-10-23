/**
* Copyright here
*/

/**  HumanPlayer class 
* @author igor
*/

#include "HumanPlayer.h"

#include <stdio.h>

namespace SeaBattle { 

HumanPlayer::HumanPlayer() : Player()
{
    initialize();
}

HumanPlayer::~HumanPlayer()
{
}

//todo implement different schemas of initializing and HumanPlayer logic
void HumanPlayer::initialize()
{
    Player::initialize();
}

void HumanPlayer::generateCoordinates(int &x, int &y)
{
#ifdef linux
    int xx;
    int yy;
    do {
        printf("x: ");
        scanf("%i", &xx);
    } while (xx < 0 || xx > 9);

    do {
        printf("y: ");
        scanf("%i", &yy);
    } while (yy < 0 || yy > 9);

    x = xx;
    y = yy;
#else
#error
#endif

}
};
