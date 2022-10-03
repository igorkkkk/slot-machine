#include "../src/SlotScore.hpp"
#include "../src/SlotImput.hpp"

void SlotScore::enter(SlotWindow* slot)
{
	slot->GetGame()->PlayWinSound();
}

void SlotScore::toggle(SlotWindow* slot)
{
	// Imput
	slot->setState(SlotImput::getInstance());
}

void SlotScore::update(SlotWindow* slot)
{
	slot->GetGame()->ComputeScore();
	slot->toggle();
}

SlotState& SlotScore::getInstance()
{
	static SlotScore singleton;
	return singleton;
}
