#include "Form1.h"
#include "FApp.h"
#include <FMedia.h>

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Media;
using namespace Osp::App;


Form1::Form1(void)
{
}

Form1::~Form1(void)
{
}

bool
Form1::Initialize()
{
	// Construct an XML form
	Construct(L"IDF_FORM1");
	pBField = NULL;
	return true;
}

result
Form1::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	char* tField = new char[100];
	for(int i = 0; i<10; i++)
		for(int j = 0; j<10; j++)
		{
			tField[i + 10* j] = 0;
		}
	tField[5 +10*5] = 1;
	tField[5 +10*6] = 1;
	tField[5 +10*7] = 1;
	tField[5 +10*8] = 1;

	tField[2 +10*5] = 1;
	tField[2 +10*4] = 1;
	tField[2 +10*3] = 1;

	tField[6 +10*2] = 1;
	tField[5 +10*2] = 1;

	pBField = new BattleFieldControl();
	pBField->Construct(Osp::Graphics::Rectangle(10,10,460,460), tField);
	pBField->AddTouchEventListener(*pBField);
	AddControl(*pBField);

	BattleFieldControl *BField = new BattleFieldControl();
	BField->Construct(Osp::Graphics::Rectangle(100,500,240,240), tField);
	BField->AddTouchEventListener(*BField);
	AddControl(*BField);



	return r;
}

result
Form1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
Form1::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{

}


