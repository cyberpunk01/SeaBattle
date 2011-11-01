/**
 * Copyright here or copyleft:)
 */

/** @brief BattleField and BattleFieldCell class
 * @author igor
 */

#ifndef BATTLEFIELD
#define BATTLEFIELD

#include <list>

namespace SeaBattle {

class Ship;

/** @class BattleFieldCell
 * @brief Represent one cell in game field */
class BattleFieldCell
{
public:
    BattleFieldCell();
    ~BattleFieldCell();

/** @enum CellState
 * @brief enum that show current battle field cell state */
enum CellState
{
    S_NONE = 0, ///< none
    S_FREE = 1, ///< free cell
    S_DECK = 2, ///< cell with ship decks
    S_DESTROYED_DECK = 4, ///< cell with destroyed ship decks
    S_CHECKED = 8, ///< free cell that was checked by user
    S_MAX = 9, ///< max
};

    /** @brief get current cell state
     * @return cell state */
    CellState getCellState() const  { return m_State; };

    /** @brief get ship placed in current cell
     * @return ship situated in cell 
     * @retval address of the ship if it's presented
     * @retval NULL if there is no ship */
    Ship*     getShip()      const  { return m_Ship;  };

    /** @brief set current cell state
     * @param st - cell state */
    void setCellState(CellState st) { m_State = st;   };

    /** @brief set ship address to current cell to associate cell with it
     * @param ship - ship associate with current cell */
    void setShip(Ship* ship)        { m_Ship  = ship; };

private:
//todo restrict copy constructor and operator=
    CellState   m_State;
    Ship        *m_Ship;
};

/** @class BattleField class
 * @brief Represent main game field in game */
class BattleField
{
public:
    BattleField();
    ~BattleField();

    /** @brief Set (x, y) cell state as checked 
     * @return previous cell state and change it for new after that */
    BattleFieldCell::CellState shootToCell(unsigned char x, unsigned char y);

    /** @brief  Check (i, j) coordinates with direction (dx, dy) and (n) decks is it available to put ship here
     * @param i  - x coordinate
     * @param j  - y coordinate
     * @param dx - direction in which ship will be located on 'X' axis
     * @param dy - direction in which ship will be located on 'Y' axis
     * @param n  - number of decks in ship
     * @return result of check
     * @retval true  - ship can be situated
     * @retval false - can't */
    bool checkCellState(unsigned char i, unsigned char j, char dx, char dy, unsigned char n);

    /** @brief Put ship into (i, j) coords with direction (dx, dy) and (n) decks 
     * @param i  - x coordinate
     * @param j  - y coordinate
     * @param dx - direction in which ship will be located on 'X' axe
     * @param dy - direction in which ship will be located on 'Y' axe
     * @param n  - number of decks in ship
     * @return put resul 
     * @retval true  - ship was situated
     * @retval false - no */
    bool putShip(unsigned char i, unsigned char j, char dx, char dy, unsigned char n);

    /** @brief Puts ships on the field */
    void fillFieldRandomly();

    /** @brief Get cell on (i, j) position 
     * @param i  - x coordinate
     * @param j  - y coordinate
     * @return pointer to field cell
     * @retval address to field cell if  0 < (i, j) < 10
     * @retval NULL otherwise */
    BattleFieldCell* getFieldCell(unsigned char i, unsigned char j);

    /** @brief Check field state
     * @retval true -  ships are available
     * @retval false - there are no ships */
    bool hasShips() const;

    /** @brief Check ship was destroyed
     * @retval true  - yes
     * @retval false - no */
    bool shipDestroyed() const { return shipWasDestroyed; };

    /** @brief Surround killed ship by checked cells
     * @param ship - ship to surround */
    void surroundDestroyedShip(const Ship *ship);

    /** @brief Debug print function - print battle field to stdout */
    void print() const;

private:
    unsigned char      m_Ships [4];
    BattleFieldCell    *m_Field[10][10];
    std::list<Ship*>   m_ShipList;
    bool               shipWasDestroyed;
};
};

#endif // BATTLEFIELD
