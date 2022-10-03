#ifndef SLOT_STATE_HPP
#define SLOT_STATE_HPP

class SlotWindow;

class SlotState
{

public:

	virtual void enter(SlotWindow* slot) = 0;
	virtual void toggle(SlotWindow* slot) = 0;
	virtual void exit(SlotWindow* slot) = 0;
	virtual void update(SlotWindow* slot) = 0;
	virtual ~SlotState() {};
};

#endif SLOT_STATE_HPP