#ifndef SLOT_HPP
#define SLOT_HPP



class SlotState;

class Slot
{
public:

	Slot();
	// Same as before
	inline SlotState* getCurrentState() const { return current_state_; }
	// In here, we'll delegate the state transition to the state
	void toggle();
	// This will get called by the current state
	void setState(SlotState& newState);

private:
	
	SlotState* current_state_;
};

#endif SLOT_HPP