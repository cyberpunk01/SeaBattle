/**
* Copyright here
*/

/**  BattleField class 
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

//todo I think we need to expand return value [for instance enum from values: killed, already checked, injured e.t.c. - bacause bool is not enought]
BattleFieldCell::CellState BattleField::shootToCell(unsigned char x, unsigned char y)
{
	//hint you need to check if cell was 'checked' before
	BattleFieldCell::CellState res = BattleFieldCell::S_NONE;

	//todo it's need not check x > 0 because of unsigned char
	if (x < 0 || x > 9 || y < 0 || y > 9) 
		return res;

	switch (m_Field[x][y]->getCellState())
	{
		case BattleFieldCell::S_DECK:
			m_Field[x][y]->setCellState(BattleFieldCell::S_DESTROYED_DECK);
			res = BattleFieldCell::S_DECK;
			break;
		case BattleFieldCell::S_CHECKED:
		case BattleFieldCell::S_DESTROYED_DECK:
			res = BattleFieldCell::S_CHECKED;
			break;
		case BattleFieldCell::S_FREE:
			m_Field[x][y]->setCellState(BattleFieldCell::S_CHECKED);
			res = BattleFieldCell::S_FREE;
			break;
		default:
			break;
	}

	return res;
}

bool BattleField::checkCellState(unsigned char x, unsigned char y, char dx, char dy, unsigned char n)
{
	if (x < 0 || x > 9 || y < 0 || y > 9) 
		return false;

	bool res = true;
	unsigned char i;
	unsigned char j;

	//todo optimize this cycle, do it without numerous calling of function getFieldCell(...)
			/*		if ( true != ((m_Field[i, j] != 0 && m_Field[i, j]->getCellState() == BattleFieldCell::S_FREE) && 
					(m_Field[i + 1, j + 1] == NULL || m_Field[i + 1, j + 1]->getCellState() == BattleFieldCell::S_FREE) && 
					(m_Field[i - 1, j - 1] == NULL || m_Field[i - 1, j - 1]->getCellState() == BattleFieldCell::S_FREE) &&
					(m_Field[i + 1, j] == NULL || m_Field[i + 1, j]->getCellState() == BattleFieldCell::S_FREE) &&
					(m_Field[i - 1, j] == NULL ||  m_Field[i - 1, j]->getCellState() == BattleFieldCell::S_FREE) &&
					(m_Field[i, j - 1] == NULL ||  m_Field[i, j - 1]->getCellState() == BattleFieldCell::S_FREE) &&
					(m_Field[i, j + 1] == NULL ||  m_Field[i, j + 1]->getCellState() == BattleFieldCell::S_FREE)) )
			 */
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

	for(i = x, j = y; i != x + dx * n || j != y + dy * n; i += dx, j += dy)
	{
		//todo I dont like this way of assignment
		getFieldCell(i, j)->setCellState(BattleFieldCell::S_DECK);
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

void BattleField::print()
{
	unsigned int i = 0, j;

	printf("-----------------------\n");

	for(j = 0; i < 10; ++i)
	{
		j = 0;
		printf("| ");
		for(; j < 10; ++j)
		{
			printf("%d ", (int)m_Field[i][j]->getCellState());
		}
		printf("| \n");
	}

	printf("-----------------------\n");
}

} //namespace
