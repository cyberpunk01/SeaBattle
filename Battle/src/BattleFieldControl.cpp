#include "BattleFieldControl.h"
#include "FApp.h"
#include <FMedia.h>



using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Media;
using namespace Osp::App;


BattleFieldControl::BattleFieldControl(void)
{
	m_pNormalBitmap = NULL;
	m_pFocusedBitmap = NULL;
	_side = 0;
}

BattleFieldControl::~BattleFieldControl(void)
{
//	if(pField)
//		delete pField;
}
result BattleFieldControl::Construct(Osp::Graphics::Rectangle rect, char* aField)
{

	m_Field = aField;

	if ((rect.height != rect.width) ||
		(rect.height % 10 > 0)		)
		return E_FAILURE;
	result r = E_SUCCESS;
	_side = rect.height/10;
	Osp::Ui::Controls::Panel::Construct(rect);

//	for(int i=0; i<100; i++)
//		_states[i] = 'f';

	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	if (pAppResource)
	{
		m_pNormalBitmap = pAppResource->GetBitmapN(L"Normal.png", BITMAP_PIXEL_FORMAT_ARGB8888);
		m_pFocusedBitmap = pAppResource->GetBitmapN(L"Focused.png", BITMAP_PIXEL_FORMAT_ARGB8888);
	}


	return r;
}



result
BattleFieldControl::OnInitializing(void)
{
	result r = E_SUCCESS;

		Draw();
		Show();
		AppLog("Field created");
	return r;
}

result
BattleFieldControl::OnDraw()
{

	result r = E_SUCCESS;


		int height = this->GetHeight();
		Osp::Graphics::Canvas *pPaint = GetCanvasN();

		for (int j=0; j< 10; j++)
			for(int i=0; i<10; i++)
			{
				switch (m_Field[i + 10*j])
				{
				case 0:
					{
						if(NULL != m_pNormalBitmap)
						{
							if (E_SUCCESS != pPaint->DrawBitmap(Rectangle(i*_side, j*_side, _side, _side), *m_pNormalBitmap ))
								AppLog("ShitHappens");
						}
						else
							AppLog("Bitmap is unavailable!");
					}
					break;
				case 1:
					{
						if(NULL != m_pFocusedBitmap)
						{
							if (E_SUCCESS != pPaint->DrawBitmap(Rectangle(i*_side, j*_side, _side, _side), *m_pFocusedBitmap ))
								AppLog("ShitHappens");
						}
						else
							AppLog("Bitmap is unavailable!");
					}
					break;
				default:
					break;
				}
			}

		if(NULL != pPaint)
			delete pPaint;

		return r;

}


result
BattleFieldControl::OnTerminating(void)
{
	result r = E_SUCCESS;

	if(NULL == m_pNormalBitmap)
		delete m_pNormalBitmap;
	if(NULL == m_pFocusedBitmap)
		delete m_pFocusedBitmap;
	// TODO: Add your termination code here

	return r;
}
//==================

void BattleFieldControl::OnTouchFocusIn (const Osp::Ui::Control &source, const Osp::Graphics::Point &tPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	//__bPressed = true;
	int x = tPosition.x;
	int y = tPosition.y;
	AppLog("OnTouchFocusIn %d, %d,", x, y);
	/*_states[0] = 'p';
	RequestRedraw(true);*/
}
void BattleFieldControl::OnTouchFocusOut (const Osp::Ui::Control &source, const Osp::Graphics::Point &tPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	//__bPressed = false;
	AppLog("OnTouchFocusOut %d, %d,", tPosition.x, tPosition.y);
	/*_states[0] = 'f';
	RequestRedraw(true);*/
}
void BattleFieldControl::OnTouchPressed (const Osp::Ui::Control &source, const Osp::Graphics::Point &tPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	//__bPressed = true;


	int x = tPosition.x/_side;
	int y = tPosition.y/_side;

	x = (x>9?9:x);
	y = (y>9?9:y);

	AppLog("OnTouchPressed %d, %d,", x, y);

	m_Field[x + 10*y] = 0;
	RequestRedraw(true);
}
void BattleFieldControl::OnTouchReleased (const Osp::Ui::Control &source, const Osp::Graphics::Point &tPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{

	int x = tPosition.x/_side;
	int y = tPosition.y/_side;

	x = (x>9?9:x);
	y = (y>9?9:y);

	AppLog("OnTouchReleased %d, %d,", x, y);
	m_Field[x + 10*y] = 1;
	RequestRedraw(true);
}















//===========
void
BattleFieldControl::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case 103:
		{
			AppLog("OK Button is clicked! \n");
		}
		break;
	default:
		break;
	}
}
