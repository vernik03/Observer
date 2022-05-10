#include <iostream>
#include <memory>

#include "Events.h"

int main()
{
	const std::string output_text = "Hello world";
	system("cls");
	system("color 4");
	std::cout << output_text;
	std::unique_ptr<MouseHoverEvent> hover_event = std::make_unique<MouseHoverEvent>();
	std::unique_ptr<Listener> change_color = std::make_unique<ChangeColor>(output_text);
	std::unique_ptr<Listener> write_log = std::make_unique<WriteLog>();

	hover_event->event->Subscribe(change_color.get());
	hover_event->event->Subscribe(write_log.get());
	hover_event->Sycle();



}