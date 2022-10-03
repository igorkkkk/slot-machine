#include "../src/Button.hpp"

Button::Button(sf::Vector2f  position, sf::Vector2f dimentions, sf::Font font, std::string text)
{
	this->lock_ = false;
	this->button_state_ = ButtonStates::kButtonIdle;
	
	this->shape_.setPosition(position);
	this->shape_.setSize(dimentions);

	this->font_ = font;
	this->text_.setFont(this->font_);
	this->text_.setString(text);
	this->text_.setFillColor(TEXT_COLOR);
	this->text_.setCharacterSize(this->character_size_);

	this->text_.setPosition(
		this->shape_.getPosition().x  + (this->shape_.getGlobalBounds().width / 2.0f) - this->text_.getGlobalBounds().width / 2.0f,
		this->shape_.getPosition().y  + (this->shape_.getGlobalBounds().height / 2.0f) - this->text_.getGlobalBounds().height / 2.0f
	);

	this->shape_.setFillColor(this->state_colors_.find(ButtonStates::kButtonIdle)->second);

	if (!button_sound_buffer_.loadFromFile(BUTTON_PRESSED_SOUND_PATH)) {}
	button_sound_.setBuffer(button_sound_buffer_);
	
}

Button::~Button()
{
}

void Button::Render(sf::RenderTarget* target)
{
	target->draw(this->shape_);
	target->draw(this->text_);
}

void Button::Update(const sf::Vector2f mousePos) 
{
	// Update state
	if ( this->shape_.getGlobalBounds().contains((mousePos)) && !lock_)
	{
		this->button_state_ = ButtonStates::kButtonHover;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->button_state_ = ButtonStates::kButtonPressed;
			this->button_sound_.play();
		}
	}
	else {
		this->button_state_ = ButtonStates::kButtonIdle;
	}

	this->shape_.setFillColor(this->state_colors_.find(button_state_)->second);
}

const bool Button::isPressed()
{
	if(this->button_state_ == ButtonStates::kButtonPressed)
		return true;

	return false;
}

void Button::Lock(bool state)
{
	lock_ = state;
}


const bool Button::isLocked()
{
	return lock_;
}

