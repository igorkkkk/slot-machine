#include "../src/SlotScore.hpp"
#include "../src/SlotRun.hpp"

void SlotRun::enter(SlotWindow* slot)
{
	slot->GetGame()->PlayPlaySound(true);
}

void SlotRun::toggle(SlotWindow* slot)
{
	// Score
	slot->setState(SlotScore::getInstance());
}

void SlotRun::exit(SlotWindow* slot)
{
	slot->GetGame()->EndRound();
	slot->GetStartButton()->Lock(false);
	slot->GetGame()->StopPlaySound();
}

SlotState& SlotRun::getInstance()
{
	static SlotRun singleton;
	return singleton;
}

void SlotRun::update(SlotWindow* slot)
{
	slot->GetStopButton()->Update(static_cast<sf::Vector2f>(sf::Mouse::getPosition(slot->GetGame()->GetWindow())));
	if (slot->GetStopButton()->isPressed())
	{
		slot->GetGame()->EndRound();
	}
	if (slot->GetGame()->ReelStop())
	{
		slot->toggle();
	}


	slot->GetGame()->Update();
}
