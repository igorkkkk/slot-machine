#include "../src/ReelStop.hpp"
#include "../src/ReelIdle.hpp"

void ReelStop::toggle(Reel* reel)
{
	// Stop to idle
	reel->setState(ReelIdle::getInstance());
}

void ReelStop::update(Reel* reel)
{
	reel->Stop();
}

ReelState& ReelStop::getInstance()
{
	static ReelStop singleton;
	return singleton;
}

void ReelStop::enter(Reel* reel)
{
}
