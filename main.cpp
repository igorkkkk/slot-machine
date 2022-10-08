#include <memory>
#include "src/SlotWindow.hpp"


int main()
{
	std::unique_ptr<SlotWindow> window_ptr_ = std::make_unique<SlotWindow>();

	sf::Thread thread(&SlotWindow::Draw, &*window_ptr_);
	thread.launch();
	window_ptr_->StartLoop();
	
	return EXIT_SUCCESS;
}
