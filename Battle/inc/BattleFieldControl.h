#ifndef _BATTLEFIELDCONTROL_H_
#define _BATTLEFIELDCONTROL_H_

#include <FBase.h>
#include <FUi.h>

class BattleFieldControl:
	 public Osp::Ui::Controls::Panel
	,public Osp::Ui::ITouchEventListener
{

// Construction
public:
	BattleFieldControl(void);
	virtual ~BattleFieldControl(void);

// Implementation
protected:

	char* m_Field;
	int _side;
	Osp::Graphics::Bitmap* m_pNormalBitmap;
	Osp::Graphics::Bitmap* m_pFocusedBitmap;

private:
	result Construct(){ return E_SUCCESS; };
public:
	result Construct(Osp::Graphics::Rectangle rect, char* );
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual result OnDraw(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	/**
	 * Notifies when an entity is touch pressed.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */

	virtual void OnTouchPressed(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo & touchInfo);

	/**
	 * Notifies when an entity is touched and held for a long time.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchLongPressed(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo){};

	/**
	 * Notifies when an entity is touch released.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchReleased(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo);

	/**
	 * Notifies when an entity is touch moved.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchMoved(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo){};

	/**
	 * Notifies when an entity is touched and double-pressed.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchDoublePressed(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo){};

	/**
	 * Notifies when an entity becomes touch focus-in.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchFocusIn(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo);

	/**
	 * Notifies when an entity becomes touch focus-out.
	 *
	 * @param[in] 	source			The source of the event
	 * @param[in] 	currentPosition	The current position
	 * @param[in] 	touchInfo		The touch event information
	 */
	virtual void OnTouchFocusOut(const Osp::Ui::Control& source,
		const Osp::Graphics::Point& currentPosition, const Osp::Ui::TouchEventInfo& touchInfo);




};

#endif	//_BATTLEFIELDCONTROL_H_
