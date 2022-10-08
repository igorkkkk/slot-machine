#ifndef REEL_HPP
#define REEL_HPP
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>

#define REEL_FIGURES_NUM 4
#define IMAGE_SIZE 384
class ReelState;

class Reel
{
public:
	Reel(sf::Vector2f position, sf::Vector2f dimentions, std::shared_ptr<sf::Clock>& game_clock_ptr);

	Reel(const Reel& obj);

	// Same as before
	inline ReelState* getCurrentState() const { return current_state_; }
	// In here, we'll delegate the state transition to the state
	void toggle();
	void Update();
	// This will get called by the current state
	void setState(ReelState& newState);
	// Computation of delta
	void ComputeDelta();
	void Stop();


	// Enum class for figures
	enum class ReelFigures
	{
		kBanana = 0,
		kRaspberry,
		kWatermelon,
		kApricot
	};

	// Create reel
	void RenderTexture(std::map<ReelFigures, sf::Texture> textures);
	// Draw the window with reel
	void RenderReel(sf::RenderWindow& slot_window);

	ReelFigures getScore();
private:
	ReelState* current_state_;
	// Circular Buffer to store picture name;
	std::vector<ReelFigures> figures_vec_;
	// Is used to move thought textures
	std::vector<ReelFigures>::iterator main_texture_iter_;
	// Delta
	float delta_spin_ = 0;
	// Reel shape
	sf::RectangleShape reel_shape_;
	// Displayed reel
	sf::RenderTexture reel_render_;

	// Spin sound
	sf::SoundBuffer spin_sound_buffer_;
	sf::Sound spin_sound_;

	float gain_ = 2.0f;
	// Reference
	std::shared_ptr<sf::Clock> current_spin_time_ptr_;
	sf::Time delta_time_;
};

#endif REEL_HPP
