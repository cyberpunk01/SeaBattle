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

    inline CellState getCellState() const { return m_State; };
    inline const Ship* getShip()    const { return m_Ship;  };

    inline void setCellState(CellState st) { m_State = st; };
    inline void getShip(const Ship* ship)  { m_Ship  = ship; };

private:
//todo restrict copy constructor and operator=
    CellState   m_State;
    const Ship *m_Ship;
};

/*** BattleField ***/
class BattleField
{
public:
    BattleField();
    ~BattleField();

    /* Set (i,j) cell state as checked */
    bool shootToCell(unsigned char x, unsigned char y);

    /* Check (i,j) coords with direction (dx, dy) and (n) decks is it available to put ship here*/
    bool checkCellState(unsigned char i, unsigned char j, char dx, char dy, unsigned char n);

    /* Put ship into (i,j) coords with direction (dx, dy) and (n) decks */
    bool putShip(unsigned char i, unsigned char j, char dx, char dy, unsigned char n);

    /* Puts ships on the field */
    void fillFieldRandomly();

    /* Get cell on (i,j) position */
    inline BattleFieldCell* getFieldCell(unsigned char i, unsigned char j) { if (i < 0 || i > 9 || j < 0 || j > 9) return NULL; return m_Field[i][j]; };

    /* Debug print func - print battle field to stdout*/
    void print();

private:
    unsigned char      m_Ships[4];
    BattleFieldCell    *m_Field[10][10];
};
};

#endif // BATTLEFIELD
