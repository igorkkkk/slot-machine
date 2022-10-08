#include "../src/Game.hpp"

#include <iostream>
#include <string>
#include "../src/ReelState.hpp"


Game::Game(sf::RenderWindow& window)
	: window_{window}, timer_ptr{std::make_shared<sf::Clock>()}
{
	for (int i = 0; i < REEL_NUM; i++)
	{
		//FIXME: add spamt pointer
		reel_storage_ptr_.push_back(new Reel(sf::Vector2f(IMAGE_SIZE / 4 + IMAGE_SIZE * i, IMAGE_SIZE / 4),
		                                     sf::Vector2f(IMAGE_SIZE,IMAGE_SIZE),
		                                     timer_ptr));
	}

	// Declare and load a texture
	for (int i = 0; i < path_cont_.size(); i++)
	{
		// Create texture
		sf::Texture texture;
		texture.loadFromFile(path_cont_.at(i));


		sprites_container_.insert(std::pair<Reel::ReelFigures, sf::Texture>(
			static_cast<Reel::ReelFigures>(i), std::move(texture)));
	}

	// Initialize sounds
	// Game sound
	if (!game_sound_buffer_.loadFromFile(GAME_SOUND_PATH))
	{
	}
	game_sound_.setBuffer(game_sound_buffer_);
	// Game win sound
	if (!game_win_sound_buffer_.loadFromFile(GAME_WIN_SOUND_PATH))
	{
	}
	game_win_sound_.setBuffer(game_win_sound_buffer_);
	// Game play sound
	if (!game_play_sound_buffer_.loadFromFile(GAME_PLAY_SOUND_PATH))
	{
	}
	game_play_sound_.setBuffer(game_play_sound_buffer_);

	// Setup text parameters
	// set the character size
	text_.setCharacterSize(24); // in pixels, not points!

	// set the color
	text_.setFillColor(SCORE_COLOR);

	// set the text style
	text_.setStyle(sf::Text::Bold);
	text_.setPosition(IMAGE_SIZE * 3 + IMAGE_SIZE / 2, IMAGE_SIZE / 2 + IMAGE_SIZE / 4);
}

Game::~Game()
{
	for (auto* el : reel_storage_ptr_)
	{
		delete el;
	}
}

sf::RenderWindow& Game::GetWindow()
{
	return window_;
}

void Game::EndRound()
{
	// TODO:
	for (auto* el : reel_storage_ptr_)
	{
		if (el->getCurrentState()->StateName() == ReelStateName::kAccelerate)
		{
			el->toggle();
		}
	}
}

void Game::NewGame(bool a)
{
	timer_ptr->restart();
	for (auto* el : reel_storage_ptr_)
	{
		// Toggle to start
		el->toggle();
	}
}

void Game::Update()
{
	for (auto* el : reel_storage_ptr_)
	{
		el->Update();
	}
}

void Game::Draw()
{
	for (auto* el : reel_storage_ptr_)
	{
		el->RenderTexture(sprites_container_);
		el->RenderReel(window_);
	}
}

void Game::ComputeScore()
{
	score_ = 0;
	for (auto* el : reel_storage_ptr_)
	{
		score_ += static_cast<int>(el->getScore());
	}
}

bool Game::ReelStop()
{
	for (auto* el : reel_storage_ptr_)
	{
		if (el->getCurrentState()->StateName() != ReelStateName::kIdle)
		{
			return false;
		}
	}
	return true;
}

void Game::DrawScore(sf::Font font)
{
	// set the string to display
	std::string result = "SCORE: ";
	result.append(std::to_string(score_));
	text_.setString(result);
	// Select the font
	text_.setFont(font);
	window_.draw(text_);
}

void Game::PlayGameSound(bool loop)
{
	game_sound_.setLoop(loop);
	game_sound_.play();
}

void Game::StopGameSound()
{
	game_sound_.stop();
}

void Game::PlayWinSound(bool loop)
{
	game_win_sound_.setLoop(loop);
	game_win_sound_.play();
}

void Game::StopWinSound()
{
	game_win_sound_.stop();
}

void Game::PlayPlaySound(bool loop)
{
	game_play_sound_.setLoop(loop);
	game_play_sound_.play();
}

void Game::StopPlaySound()
{
	game_play_sound_.stop();
}
