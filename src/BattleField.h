/**
* Copyright here or copyleft)
*/

/**  BattleField class 
* @author igor
*/

#ifndef BATTLEFIELD
#define BATTLEFIELD

#include <list>

namespace SeaBattle {

class Ship;

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
    S_DESTROYED_DECK = 4,
    S_CHECKED = 8,
    S_MAX = 9,
};

    CellState getCellState() const  { return m_State; };
    Ship*     getShip()      const  { return m_Ship;  };

    void setCellState(CellState st) { m_State = st;   };
    void setShip(Ship* ship)        { m_Ship  = ship; };

private:
//todo restrict copy constructor and operator=
    CellState   m_State;
    Ship        *m_Ship;
};

/*** BattleField ***/
class BattleField
{
public:
    BattleField();
    ~BattleField();

    /* Set (i,j) cell state as checked */
    /* Return previous cell state and change it for new after that */
    BattleFieldCell::CellState shootToCell(unsigned char x, unsigned char y);

    /* Check (i,j) coords with direction (dx, dy) and (n) decks is it available to put ship here*/
    bool checkCellState(unsigned char i, unsigned char j, char dx, char dy, unsigned char n);

    /* Put ship into (i,j) coords with direction (dx, dy) and (n) decks */
    bool putShip(unsigned char i, unsigned char j, char dx, char dy, unsigned char n);

    /* Puts ships on the field */
    void fillFieldRandomly();

    /* Get cell on (i,j) position */
    BattleFieldCell* getFieldCell(unsigned char i, unsigned char j) const;

    /* Check field state: false - there are no ships, true - ships are available */
    bool hasShips() const;

    /* Debug print func - print battle field to stdout*/
    void print();

private:
    unsigned char      m_Ships [4];
    BattleFieldCell    *m_Field[10][10];
    std::list<Ship*>   m_ShipList;
};
};

#endif // BATTLEFIELD
