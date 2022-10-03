#include "Slot.hpp"
#include "../src/Slot.hpp"
#include "../src/SlotImput.hpp"


Slot::Slot()
{
	current_state_ = &SlotImput::getInstance();

}

void Slot::setState(SlotState& newState)
{
	current_state_->exit(this); // do stuff before we change state
	current_state_ = &newState; // change state
	current_state_->enter(this); // do stuff after we change state
}


void Slot::toggle()
{
	// Delegate the task of determining the next state to the current state!
	current_state_->toggle(this);
}

