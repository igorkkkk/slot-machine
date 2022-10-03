#include "ReelStart.hpp"
#include "../src/ReelAccelerate.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
void ReelStart::toggle(Reel* reel)
{
	// Start to acceleration
	reel->setState(ReelAccelerate::getInstance());
}

void ReelStart::update(Reel* reel)
{
	reel->toggle();
}

ReelState& ReelStart::getInstance()
{
	static ReelStart singleton;
	return singleton;
}

void ReelStart::enter(Reel* reel) 
{

}