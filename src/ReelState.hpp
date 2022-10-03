#ifndef REEL_STATE_HPP
#define REEL_STATE_HPP

class Reel;
enum class ReelStateName {
	kIdle = 0,
	kStart,
	kAccelerate,
	kStop
};
class ReelState
{

public:

	ReelStateName state_name = ReelStateName::kIdle;
	virtual void enter(Reel* reel) = 0;
	virtual void toggle(Reel* reel) = 0;
	virtual void exit(Reel* reel) = 0;
	virtual void update(Reel* reel) = 0;
	virtual ReelStateName StateName() = 0;
	virtual ~ReelState() {};
};

#endif REEL_STATE_HPP