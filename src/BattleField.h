/**
* Copyright here
*/

/**  BattleField class 
* @author igor
*/

#ifndef BATTLEFIELD
#define BATTLEFIELD

#include "Ship.h"

namespace SeaBattle {


/*** BattleFieldCell ***/
class BattleFieldCell
{
public:
    BattleFieldCell();
    ~BattleFieldCell();

enum CellState
{
    S_NONE = 0,
    S_FREE = 1,
    S_DECK = 2,
    S_CHECKED = 4,
    S_MAX = 5,
};

//private:
//todo restrict copy constructor and operator=
    CellState  m_State;
    const Ship * const m_Ship;
};

/*** BattleField ***/
class BattleField
{
public:
    BattleField();
    ~BattleField();

    /* Check (i,j) cell as destroyed */
    bool ShootToCell(unsigned char i, unsigned char j);

    /* Put ship into (i,j) coords with direction (d) and (n) decks */
    bool PutShip(unsigned char i, unsigned char j, unsigned char d, unsigned char n);

private:
    unsigned char      m_Sips[4];
    BattleFieldCell    *m_Field[10][10];
//    std::vector<unsigned char> m_Decks;        
};
};

#endif // BATTLEFIELD
