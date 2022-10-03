#include "../src/SlotImput.hpp"
#include "../src/SlotRun.hpp"

void SlotImput::toggle(SlotWindow* slot)
{
	// Run
	slot->setState(SlotRun::getInstance());
}

SlotState& SlotImput::getInstance()
{
	static SlotImput singleton;
	return singleton;
}

void SlotImput::enter(SlotWindow* slot)
{
	slot->GetGame()->PlayGameSound();
}
void SlotImput::update(SlotWindow* slot)
{
	
	slot->GetStartButton()->Update(static_cast<sf::Vector2f>(sf::Mouse::getPosition(slot->GetGame()->GetWindow())));
	if (slot->GetStartButton()->isPressed() && !slot->GetStartButton()->isLocked())
	{
		slot->toggle();
	}
}
void SlotImput::exit(SlotWindow* slot)
{
	slot->GetStartButton()->Lock(true);
	slot->GetGame()->NewGame(true);
}