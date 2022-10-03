#include <memory>
#include "src/SlotWindow.hpp"


int main()
{
	std::unique_ptr<SlotWindow> window_ptr_ = std::make_unique<SlotWindow>();
	window_ptr_->StartLoop();
	return EXIT_SUCCESS;
}
