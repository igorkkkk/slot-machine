#ifndef SLOT_IMPUT_HPP
#define SLOT_IMPUT_HPP

#include "../src/SlotState.hpp"
#include "../src/SlotWindow.hpp"

class SlotImput :
	public SlotState
{
public:
	void enter(SlotWindow* slot);
	void toggle(SlotWindow* slot);
	void exit(SlotWindow* slot);
	void update(SlotWindow* slot);
	static SlotState& getInstance();

private:
	SlotImput(){};
	SlotImput(const SlotImput& other);
	SlotImput& operator=(const SlotImput& other);
};

#endif SLOT_IMPUT_HPP