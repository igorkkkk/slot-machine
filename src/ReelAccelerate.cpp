#include "../src/ReelAccelerate.hpp"
#include "../src/ReelStop.hpp"

void ReelAccelerate::toggle(Reel* reel)
{
	// Acceleration to stop
	reel->setState(ReelStop::getInstance());
}

void ReelAccelerate::update(Reel* reel)
{
	reel->ComputeDelta();
}

ReelState& ReelAccelerate::getInstance()
{
	static ReelAccelerate singleton;
	return singleton;
}

void ReelAccelerate::enter(Reel* reel)
{
	
}
