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
: hitFlag   (false)
, turnOn180 (false)
, turnOn90  (false)
, dx (1)
, dy (0)
, hitedX (-1)
, hitedY (-1)
, firstHitPosX (-1)
, firstHitPosY (-1)
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

    randomDirection();
}

void AIPlayer::generateCoordinates(int &x, int &y)
{
    if (false == hitFlag)
    {
        firstHitPosX = rand() % 10;
        firstHitPosY = rand() % 10;

        hitedX = x = firstHitPosX;
        hitedY = y = firstHitPosY;
    
        printf("\nAIPlayer turn: x-%i, y-%i\n", x, y);

        return;
    }

    x = hitedX + dx;
    y = hitedY + dy;

    //todo debug print - delete
    printf("\nAIPlayer turn: x-%i, y-%i\n", x, y);
}

void AIPlayer::shootResult(unsigned char x, unsigned char y, BattleFieldCell::CellState result)
{
    if (BattleFieldCell::S_DECK == result)
    {
        hitFlag = true;
        hitedX = x;
        hitedY = y;

        return;
    }

    if (hitFlag)
    {
        hitedX = firstHitPosX;
        hitedY = firstHitPosY;

        // change the direction of fire (180 degree)
        if (false == turnOn180)
        {
            turnOn180  = true;
            dx *= -1;
            dy *= -1;
        }
        else
        {
            // change the axis of fire (90 degree)
            if (false == turnOn90)
            {
                turnOn180 = false;
                turnOn90  = true;
                dx = (dx + 1) % 2;
                dy = (dy + 1) % 2;
            }
            else
            {
                // not reachable code because ship destroyed, 
                // fire was finished and all flags reset
            }
        }
    }
}

void AIPlayer::shipWasDestroyed()
{
    // ship was destroyed => killed ship was surrounded by checked cells
    // we should to reset flags,
    // and apply random direction for next fire
    resetAllFlags(); 
    randomDirection(); 
}

void AIPlayer::randomDirection()
{
    dx = rand() % 2;
    dy = (dx + 1) % 2;

    if (rand() % 2)
    {
       dx *= -1; 
       dy *= -1; 
    }
}

void AIPlayer::resetAllFlags()
{
    turnOn180 = false;
    turnOn90  = false;
    hitFlag   = false;
}
};
