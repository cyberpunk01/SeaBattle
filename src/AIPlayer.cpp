/**
* Copyright here
*/

/**  AIPlayer class 
* @author igor
*/

#include "AIPlayer.h"

#include <stdlib.h>
#include <stdio.h>

namespace SeaBattle { 

AIPlayer::AIPlayer()
{
    initialize();
}

AIPlayer::~AIPlayer()
{
}

//todo implement different schemas of initializing and AIPlayer logic
void AIPlayer::initialize()
{
    Player::initialize();
}


void AIPlayer::generateCoordinates(unsigned char &x, unsigned char &y) const
{
	 x = rand() % 10;
	 y = rand() % 10;
    
    //todo debug print - delete
    printf("\nAIPlayer turn: x-%i, y-%i\n", x, y);
}

};
