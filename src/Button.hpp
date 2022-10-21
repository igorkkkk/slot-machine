#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

#define IDLE_COLOR sf::Color(239,184,255)
#define ACTIVE_COLOR sf::Color(204,103,255)
#define HOVER_COLOR sf::Color(153,103,255)
#define TEXT_COLOR sf::Color(50,50,0)

#define BUTTON_PRESSED_SOUND_PATH "resources/button-pressed.wav"

enum class ButtonStates
{
	kButtonIdle = 0,
	kButtonPressed,
	kButtonHover
};

class Button
{
private:
	sf::RectangleShape shape_;
	sf::Font font_;
	sf::Text text_;

	int character_size_ = 18;

	bool lock_;
	ButtonStates button_state_;

	// Load the sounds used in the game
	sf::SoundBuffer button_sound_buffer_;
	sf::Sound button_sound_;

	std::map<ButtonStates, sf::Color> state_colors_{
		{ButtonStates::kButtonIdle,IDLE_COLOR},
		{ButtonStates::kButtonPressed,ACTIVE_COLOR},
		{ButtonStates::kButtonHover,HOVER_COLOR}
	};


public:
	Button(sf::Vector2f point, sf::Vector2f dimentions, sf::Font font,
	       std::string text);
	~Button();

	void Render(sf::RenderTarget* target);
	void Update(const sf::Vector2f mousePos);

	const bool isPressed();
	void Lock(bool state);
	const bool isLocked();
};

#endif // BUTTON_HPP
