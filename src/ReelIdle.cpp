#include "../src/ReelIdle.hpp"
#include "../src/ReelStart.hpp"

void ReelIdle::toggle(Reel* reel)
{
	// Idle to start
	reel->setState(ReelStart::getInstance());
}

ReelState& ReelIdle::getInstance()
{
	static ReelIdle singleton;
	return singleton;
}
void ReelIdle::update(Reel* reel)
{
	
}