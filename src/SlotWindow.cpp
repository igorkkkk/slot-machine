#include "../src/SlotWindow.hpp"
#include "../src/SlotImput.hpp"

SlotWindow::SlotWindow()
	: window_{
		  sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32),
		  "SFML Slot Machine",
		  sf::Style::Titlebar | sf::Style::Close
	  }, game_ptr_{new Game(window_)}
{
	window_.setFramerateLimit(kFramerateLimit);
	window_.setVerticalSyncEnabled(true);
	window_.setActive(false);

	if (!font_.loadFromFile(FONT_PATH))
	{
	}

	start_ptr_ = new Button(sf::Vector2f(IMAGE_SIZE * 3 + IMAGE_SIZE / 2, IMAGE_SIZE / 4),
	                        sf::Vector2f(IMAGE_SIZE / 4, IMAGE_SIZE / 8),
	                        font_, std::string("Start"));
	stop_ptr_ = new Button(sf::Vector2f(IMAGE_SIZE * 3 + IMAGE_SIZE / 2, IMAGE_SIZE + IMAGE_SIZE / 8),
	                       sf::Vector2f(IMAGE_SIZE / 4, IMAGE_SIZE / 8),
	                       font_, std::string("Stop"));

	current_state_ = &SlotImput::getInstance();
	timer_.restart();
}


void SlotWindow::StartLoop()
{
	if (timer_.getElapsedTime().asMilliseconds() % 10 == 0)
	{
		while (window_.isOpen())
		{
			// Handle events
			sf::Event event;
			while (window_.pollEvent(event))
			{
				// Window closed or escape key pressed: exit
				if ((event.type == sf::Event::Closed) ||
					((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				{
					window_.close();
					break;
				}
			}
			current_state_->update(this);
		}
	}
}

void SlotWindow::Draw()
{
	while (window_.isOpen())
	{
		// Draw all content
		window_.clear(BACKGROUND_COLOR);

		game_ptr_->Draw();
		start_ptr_->Render(&window_);
		stop_ptr_->Render(&window_);
		game_ptr_->DrawScore(font_);
		window_.display();
	}
}

SlotWindow::~SlotWindow()
{
	delete start_ptr_;
	delete stop_ptr_;
	delete game_ptr_;
}

void SlotWindow::setState(SlotState& newState)
{
	current_state_->exit(this); // do stuff before we change state
	current_state_ = &newState; // change state
	current_state_->enter(this); // do stuff after we change state
}


void SlotWindow::toggle()
{
	// Delegate the task of determining the next state to the current state!
	current_state_->toggle(this);
}


Button* SlotWindow::GetStartButton()
{
	return start_ptr_;
}

Button* SlotWindow::GetStopButton()
{
	return stop_ptr_;
}

Game* SlotWindow::GetGame()
{
	return game_ptr_;
}

sf::Font SlotWindow::GetFont()
{
	return font_;
}
