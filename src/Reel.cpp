#include "Reel.hpp"
#include <ctime>
#include <random>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include "../src/ReelState.hpp"
#include "../src/ReelIdle.hpp"

Reel::Reel(sf::Vector2f position, sf::Vector2f dimentions, std::shared_ptr<sf::Clock>& game_clock_ptr)
{
	current_state_ = &ReelIdle::getInstance();

	// Set window dimentions and position
	reel_shape_.setPosition(position);
	reel_shape_.setSize(dimentions);
	reel_shape_.setOutlineColor(sf::Color::Black);
	reel_shape_.setOutlineThickness(5);

	// Randomly initialize reel
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1,
	                                                               REEL_FIGURES_NUM); // distribution in range [1, 4]

	std::unordered_set<ReelFigures> tmp_cont;
	while (tmp_cont.size() < REEL_FIGURES_NUM)
	{
		ReelFigures insert = static_cast<ReelFigures>(dist6(rng) - 1);

		tmp_cont.insert(insert);
	}
	for (auto el : tmp_cont)
	{
		figures_vec_.push_back(el);
	}


	main_texture_iter_ = figures_vec_.begin();
	current_spin_time_ptr_ = game_clock_ptr;
	delta_time_ = sf::seconds(std::rand() % 4 + 15.0f);
}

void Reel::setState(ReelState& newState)
{
	current_state_->exit(this); // Do suff before we change state
	current_state_ = &newState; // Change state
	current_state_->enter(this); // Do stuff after we change state
}

void Reel::RenderTexture(std::map<ReelFigures, sf::Texture> textures)
{
	//draw texture of imgs
	reel_render_.create(IMAGE_SIZE, IMAGE_SIZE * REEL_FIGURES_NUM);
	reel_render_.clear(sf::Color(100, 130, 100));

	// Count move
	if ((int(std::rint(delta_spin_)) % IMAGE_SIZE) >= (IMAGE_SIZE*40.0f/48.0f) && delta_spin_)
	{
		auto val0 = figures_vec_.at(2);
		auto val1 = figures_vec_.at(3);
		figures_vec_.at(2) = figures_vec_.at(0);
		figures_vec_.at(3) = figures_vec_.at(1);
		figures_vec_.at(0) = val0;
		figures_vec_.at(1) = val1;

		main_texture_iter_ = figures_vec_.begin();
		delta_spin_ = 0;
	}

	auto iter = figures_vec_.begin(); 
	for (int i = 0; iter != figures_vec_.end(); iter++, i++)
	{
		// Create a sprite
		sf::Sprite sprite;
		sprite.setTexture(textures.find(*iter)->second);
		sprite.scale(0.5f, 0.5f);

		sprite.setPosition(float(IMAGE_SIZE / 4), float(IMAGE_SIZE / 2 * i));

		reel_render_.draw(sprite);
	}

	reel_render_.display();
	//TODO cut texture or draw part with no offset
}

void Reel::RenderReel(sf::RenderWindow& slot_window)
{
	sf::Sprite local = sf::Sprite(reel_render_.getTexture());
	local.setPosition(reel_shape_.getPosition());
	sf::IntRect tmp(0,
	                int(delta_spin_) % (IMAGE_SIZE),
	                reel_shape_.getSize().x, reel_shape_.getSize().y);
	local.setTextureRect(tmp);
	slot_window.draw(reel_shape_);
	slot_window.draw(local);
	
}

void Reel::ComputeDelta()
{
	if (current_spin_time_ptr_->getElapsedTime() < delta_time_ &&
		(current_spin_time_ptr_->getElapsedTime().asMilliseconds() % 4 == 0))
	{
		int delta_per_tick = std::rint(
			float(gain_ / 2) * (std::pow(current_spin_time_ptr_->getElapsedTime().asMilliseconds() / 1000, 2) *
				delta_time_.asMilliseconds() / 1000 -
				std::pow(current_spin_time_ptr_->getElapsedTime().asMilliseconds() / 1000, 3)));
		//delta_per_tick = (delta_per_tick % 8 == 0)  ? delta_per_tick : delta_per_tick - (delta_per_tick % 8);
		delta_spin_ += delta_per_tick;// 8 * (delta_per_tick % (IMAGE_SIZE / 8));
	}
	else if (current_spin_time_ptr_->getElapsedTime() >= delta_time_)
	{
		toggle();
	}
}

void Reel::Stop()
{
	if (delta_spin_ != float(IMAGE_SIZE / 4))
	{
		
		delta_spin_ += 4;
		if (std::fmodf(delta_spin_, float(IMAGE_SIZE / 4)) < float(IMAGE_SIZE) / 16)
		{
			delta_spin_ = IMAGE_SIZE / 4;
		}
	}
	else
	{
		toggle();
	}
}

void Reel::toggle()
{
	// Delegate the task of determining the next state to the current state
	current_state_->toggle(this);
}

void Reel::Update()
{
	current_state_->update(this);
}


Reel::ReelFigures Reel::getScore()
{
	return figures_vec_.at(1);
}
