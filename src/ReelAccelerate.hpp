#ifndef REEL_ACCELERATE_HPP
#define REEL_ACCELERATE_HPP

#include "../src/ReelState.hpp"
#include "../src/Reel.hpp"

class ReelAccelerate :
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
	ReelAccelerate() { state_name = static_cast<ReelStateName>(2); }
	ReelAccelerate(const ReelAccelerate& other);
	ReelAccelerate& operator=(const ReelAccelerate& other);
};

#endif REEL_ACCELERATE_HPP
