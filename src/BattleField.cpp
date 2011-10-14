/**
* Copyright here
*/

/**  
* @brief  BattleField class 
* @author igor
*/

#include "BattleField.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace SeaBattle
{

/*** BattleFieldCell ***/
BattleFieldCell::BattleFieldCell()
: m_State (BattleFieldCell::S_FREE),
  m_Ship (NULL)
{
}

BattleFieldCell::~BattleFieldCell()
{
}

/*** BattleField ***/
BattleField::BattleField()
{
	/* initialize random seed: */
	srand ( time(NULL) );

	unsigned int i = 0, j; 

	for(; i < 4; ++i)
	{
		m_Ships[i] = 0;
	}

	i = 0;
	for(; i < 10; ++i)
	{
		j = 0;
		for(; j < 10; ++j)
		{
			m_Field[i][j] = new BattleFieldCell();
		}
	}
}

BattleField::~BattleField()
{
}

BattleFieldCell::CellState BattleField::shootToCell(unsigned char x, unsigned char y)
{
	//todo it's need not check x > 0 because of unsigned char
	if (x < 0 || x > 9 || y < 0 || y > 9) 
		return BattleFieldCell::S_NONE;

	switch (m_Field[x][y]->getCellState())
	{
		case BattleFieldCell::S_DECK:
            // ship was killed - decrease corresponding ships count
            if (m_Field[x][y]->getShip()->destroyDeck())
                m_Ships[m_Field[x][y]->getShip()->getSize() - 1] -= 1;

			m_Field[x][y]->setCellState(BattleFieldCell::S_DESTROYED_DECK);
			return BattleFieldCell::S_DECK;
		case BattleFieldCell::S_CHECKED:
			return BattleFieldCell::S_CHECKED;
		case BattleFieldCell::S_DESTROYED_DECK:
			return BattleFieldCell::S_DESTROYED_DECK;
		case BattleFieldCell::S_FREE:
			m_Field[x][y]->setCellState(BattleFieldCell::S_CHECKED);
			return BattleFieldCell::S_FREE;
		default:
			break;
	}
}

bool BattleField::checkCellState(unsigned char x, unsigned char y, char dx, char dy, unsigned char n)
{
	if (x < 0 || x > 9 || y < 0 || y > 9) 
		return false;

	bool res = true;
	unsigned char i;
	unsigned char j;

	// it done with calling of function getFieldCell() to check return type for NULL 
	for(i = x, j = y; i != x + dx * n || j != y + dy * n; i += dx, j += dy)
	{
		if ( true != (  (getFieldCell(i, j) != 0 && getFieldCell(i, j)->getCellState() == BattleFieldCell::S_FREE) && 
					(getFieldCell(i + 1, j + 1) == NULL || getFieldCell(i + 1, j + 1)->getCellState() == BattleFieldCell::S_FREE) && 
					(getFieldCell(i - 1, j - 1) == NULL || getFieldCell(i - 1, j - 1)->getCellState() == BattleFieldCell::S_FREE) &&
					(getFieldCell(i - 1, j + 1) == NULL || getFieldCell(i - 1, j + 1)->getCellState() == BattleFieldCell::S_FREE) &&
					(getFieldCell(i + 1, j - 1) == NULL || getFieldCell(i + 1, j - 1)->getCellState() == BattleFieldCell::S_FREE) &&
					(getFieldCell(i + 1, j) == NULL ||  getFieldCell(i + 1, j)->getCellState() == BattleFieldCell::S_FREE) &&
					(getFieldCell(i - 1, j) == NULL ||  getFieldCell(i - 1, j)->getCellState() == BattleFieldCell::S_FREE) &&
					(getFieldCell(i, j - 1) == NULL ||  getFieldCell(i, j - 1)->getCellState() == BattleFieldCell::S_FREE) &&
					(getFieldCell(i, j + 1) == NULL ||  getFieldCell(i, j + 1)->getCellState() == BattleFieldCell::S_FREE)
			     )
		   )
		{
			res = false;
			break; 
		}
	}

	return res;
}

bool BattleField::putShip(unsigned char x, unsigned char y, char dx, char dy, unsigned char n)
{
	if (checkCellState(x, y, dx, dy, n) == false)
		return false;

    unsigned char i; 
    unsigned char j; 
    Ship *ship (new Ship(n));
    m_Ships[n - 1] += 1;

    for(i = x, j = y; i != x + dx * n || j != y + dy * n; i += dx, j += dy)
    {
        //todo I dont like this way of assignment - why?
        m_Field[i][j]->setCellState(BattleFieldCell::S_DECK);
        m_Field[i][j]->setShip(ship);
    }

    return true;
}

void BattleField::fillFieldRandomly()
{
	unsigned char x;
	unsigned char y;

	char dx;
	char dy;

	unsigned char i;
	unsigned char j;

	for (i = 4; i > 0; --i)
	{
		for (j = 5 - i; j > 0; --j)
		{
			do {

				x  = rand() % 10;
				y  = rand() % 10;

				dx = rand() % 10;
				dy = rand() % 10;

				//apply random, different direction for ship's location
				switch (rand() % 2)
				{
					case 0:
						dx = 1;
						dy = 0;
						break;
					case 1:
						dx = 0;
						dy = 1;
						break;
					default:
						break;
				}

				//apply random, different signs for dx and dy
				switch (rand() % 2)
				{
					case 0:
						dx *= -1;
						dy *= -1;
						break;
					case 1:
					default:
						break;
				}
			} while (putShip(x, y, dx, dy, i) != true);
		} //for
	} //for
}

BattleFieldCell* BattleField::getFieldCell(unsigned char i, unsigned char j) const
{ 
    if (i < 0 || i > 9 || j < 0 || j > 9) 
        return NULL;

    return m_Field[i][j]; 
}

bool BattleField::hasShips() 
{ 
    for (int i = 0; i < 4; ++i)
        if (m_Ships[i] > 0)
            return true; 
    
    return false;
}

void BattleField::print()
{
	unsigned int i, j;

	printf("\n-----------------------\n");

	for(i = 0; i < 10; ++i)
	{
		printf("| ");
		for(j = 0; j < 10; ++j)
		{
//todo uncoment in release
//            if (BattleFieldCell::S_DECK == m_Field[j][i]->getCellState())
//    			printf("%d ", (int)BattleFieldCell::S_FREE);
//            else
    			printf("%d ", (int)m_Field[j][i]->getCellState());
		}
		printf("| \n");
	}

	printf("-----------------------\n");
}

} //namespace
