#ifndef REEL_START_HPP
#define REEL_START_HPP

#include "../src/ReelState.hpp"
#include "../src/Reel.hpp"

class ReelStart :
    public ReelState
{
public:
public:
	void enter(Reel* reel);
	void toggle(Reel* reel);
	void exit(Reel* reel) {};
	void update(Reel* reel);
	static ReelState& getInstance();
	ReelStateName StateName()
	{
		return state_name;
	}
private:
	ReelStart() { state_name = static_cast<ReelStateName>(1); }
	ReelStart(const ReelStart& other);
	ReelStart& operator=(const ReelStart& other);
};

#endif REEL_START_HPP
