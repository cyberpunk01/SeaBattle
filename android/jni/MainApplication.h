#include "../../include/AIPlayer.h"
#include "../../include/HumanPlayer.h"
#include "../../include/Player.h"
#include "../../include/BattleField.h"
#include "../../include/Ship.h"

using namespace SeaBattle;

class MainApplication
{
	private:
		AIPlayer* aiPlayer;
		HumanPlayer* hPlayer;
		BattleFieldCell::CellState res;

    public:
        MainApplication();
        ~MainApplication();

        int  Shoot(int x, int y);
        int  AIShoot();
        void SetEasyGame(bool level);
        int* GetFieldArray(bool player);
};
