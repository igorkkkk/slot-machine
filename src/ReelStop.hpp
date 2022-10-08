#ifndef REEL_STOP_HPP
#define REEL_STOP_HPP
#include "../src/ReelState.hpp"
#include "../src/Reel.hpp"

class ReelStop :
	public ReelState
{
public:
	void enter(Reel* reel);
	void toggle(Reel* reel);

	void exit(Reel* reel)
	{
	}

	void update(Reel* reel);
	static ReelState& getInstance();

	ReelStateName StateName()
	{
		return state_name;
	}

private:
	ReelStop() { state_name = static_cast<ReelStateName>(3); }
	ReelStop(const ReelStop& other);
	ReelStop& operator=(const ReelStop& other);
};
#endif REEL_STOP_HPP
