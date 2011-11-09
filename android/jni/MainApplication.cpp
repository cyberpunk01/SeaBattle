#include "MainApplication.h"

MainApplication::MainApplication()
{
	aiPlayer = new AIPlayer();
	hPlayer  = new HumanPlayer();
	res = BattleFieldCell::S_NONE;
	
	hPlayer->setListener(aiPlayer);
}

MainApplication::~MainApplication()
{
	
}

int MainApplication::Shoot(int x, int y)
{
	aiPlayer->redrawField();
	if (aiPlayer->hasShips() == false)
	{
		//TODO Add message YOU WIN!
		return 0;
	}
	return (int)aiPlayer->shoot(x, y);
}

void MainApplication::SetEasyGame(bool level)
{
	aiPlayer->setEasyGameLevel(level);
}

int MainApplication::AIShoot()
{
	char x, y;
	do {
        hPlayer->redrawField();
        if (hPlayer->hasShips() == false)
        {
            //TODO Add message AI Player WIN
            return 0;
        }
        aiPlayer->generateCoordinates(x, y);

        res = hPlayer->shoot(x, y);

    } while (res != BattleFieldCell::S_FREE);
    return (int)res;
}

int* MainApplication::GetFieldArray(bool player)
{
    if (player)
        return aiPlayer->getFieldArray();
    else
        return hPlayer->getFieldArray();
}
