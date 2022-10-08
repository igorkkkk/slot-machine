#ifndef SLOT_WINDOW_HPP
#define SLOT_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include "../src/Button.hpp"
#include "../src/Game.hpp"


#define FONT_PATH "resources/sansation.ttf"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 600

#define BACKGROUND_COLOR sf::Color(100,100,150)
class SlotState;

class SlotWindow
{
public:
	SlotWindow();
	// Same as before
	inline SlotState* getCurrentState() const { return current_state_; }
	// In here, we'll delegate the state transition to the state
	void toggle();
	// This will get called by the current state
	void setState(SlotState& newState);

	Button* GetStartButton();
	Button* GetStopButton();
	Game* GetGame();
	sf::Font GetFont();

	~SlotWindow();
	void StartLoop();


	sf::RenderWindow* GetWindow() { return &window_; }
	void Draw();

private:
	SlotState* current_state_;

	// Create the window of the application
	sf::RenderWindow window_;

	Game* game_ptr_;
	Button* start_ptr_;
	Button* stop_ptr_;

	sf::Font font_;
	sf::Clock timer_;
	static constexpr std::size_t kFramerateLimit{60};
};


#endif SLOT_WINDOW_HPP
