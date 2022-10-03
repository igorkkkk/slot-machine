#ifndef SLOT_RUN_HPP
#define SLOT_RUN_HPP

#include "../src/SlotState.hpp"
#include "../src/SlotWindow.hpp"

class SlotRun :
	public SlotState
{
public:
	void enter(SlotWindow* slot);
	void toggle(SlotWindow* slot);
	void exit(SlotWindow* slot);
	void update(SlotWindow* slot);
	static SlotState& getInstance();

private:
	SlotRun(){};
	SlotRun(const SlotRun& other);
	SlotRun& operator=(const SlotRun& other);
};

#endif SLOT_RUN_HPP