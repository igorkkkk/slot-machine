#ifndef SLOT_SCORE_HPP
#define SLOT_SCORE_HPP

#include "../src/SlotState.hpp"
#include "../src/SlotWindow.hpp"

class SlotScore :
	public SlotState
{
public:
	void enter(SlotWindow* slot);
	void toggle(SlotWindow* slot);
	void exit(SlotWindow* slot) {}
	void update(SlotWindow* slot);
	static SlotState& getInstance();

private:
	SlotScore(){};
	SlotScore(const SlotScore& other);
	SlotScore& operator=(const SlotScore& other);
};

#endif SLOT_RUN_HPP