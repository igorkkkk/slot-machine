#ifndef REEL_IDLE_HPP
#define REEL_IDLE_HPP

#include "../src/ReelState.hpp"
#include "../src/Reel.hpp"

class ReelIdle :
    public ReelState
{
public:
	void enter(Reel* reel) {}
	void toggle(Reel* reel);
	void exit(Reel* reel) {}
	void update(Reel* reel);
	static ReelState& getInstance();
	ReelStateName StateName()
	{
		return state_name;
	}
private:
	ReelIdle() { state_name = static_cast<ReelStateName>(0); }
	ReelIdle(const ReelIdle& other);
	ReelIdle& operator=(const ReelIdle& other);
};

#endif REEL_IDLE_HPP
