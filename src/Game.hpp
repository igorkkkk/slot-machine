#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Reel.hpp"
#include <vector>
#include <string>

#define GAME_SOUND_PATH "resources/intro.wav"
#define GAME_WIN_SOUND_PATH "resources/win.wav"
#define GAME_PLAY_SOUND_PATH "resources/wheel.wav"

#define BANANAS_PATH "resources/bananas.png"
#define RASPBERRY_PATH "resources/raspberry.png"
#define WATERMELON_PATH "resources/watermelon.png"
#define APRICOT_PATH "resources/apricot.png"

#define REEL_NUM 3

#define SCORE_COLOR sf::Color(100,190,50)

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	sf::RenderWindow& GetWindow();

	void EndRound();
	void NewGame(bool a);
	void Update();
	void Draw();
	void ComputeScore();
	bool ReelStop();
	void DrawScore(sf::Font);

	void PlayGameSound(bool loop = false);
	void StopGameSound();
	void PlayWinSound(bool loop = false);
	void StopWinSound();
	void PlayPlaySound(bool loop = false);
	void StopPlaySound();
private:
	sf::RenderWindow& window_;

	std::vector<Reel*> reel_storage_ptr_;

	std::vector<std::string> path_cont_{BANANAS_PATH,RASPBERRY_PATH,WATERMELON_PATH,APRICOT_PATH};
	std::map<Reel::ReelFigures, sf::Texture> sprites_container_;
	std::shared_ptr<sf::Clock> timer_ptr;

	sf::Text text_;
	int score_ = 0;
	// Game sound
	sf::SoundBuffer game_sound_buffer_;
	sf::Sound game_sound_;
	// Game win sound
	sf::SoundBuffer game_win_sound_buffer_;
	sf::Sound game_win_sound_;
	// Game play sound
	sf::SoundBuffer game_play_sound_buffer_;
	sf::Sound game_play_sound_;
};

#endif GAME_HPP
