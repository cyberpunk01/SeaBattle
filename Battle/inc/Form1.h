#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FUi.h>
#include "BattleFieldControl.h"


class Form1 :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	Form1(void);
	virtual ~Form1(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_OK = 101;
	static const int ID_ICONLIST_MINE = 201;
	static const int ID_ICONLIST_THEIR = 202;



	BattleFieldControl *pBField;
	Osp::Ui::Controls::IconList *__pIconListLeft;
	Osp::Ui::Controls::IconList *__pIconListRight;


public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif	//_FORM1_H_
