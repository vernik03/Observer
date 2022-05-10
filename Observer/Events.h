#pragma once
#include <Windows.h>
#include <iostream>
#include <memory>

#include "Listeners.h"

class EventManager
{
public:
	EventManager() {};
	virtual ~EventManager() {};

	virtual void Subscribe(Listener* listener) {
		listeners.insert(listener);
	}

	virtual void Unsubscribe(Listener* listener) {
		listeners.erase(listener);
	}

	virtual void Notify(bool flag) {
		for (auto listener : listeners) {
			listener->GetFlag(flag);
		}
	}

private:
	std::set<Listener*> listeners;

};

class MouseHoverEvent
{
public:
	MouseHoverEvent() : hStdOut(GetStdHandle(STD_OUTPUT_HANDLE)), hWnd(GetConsoleWindow()), delay(200), event(std::make_unique<EventManager>()) {
		is_mouse_in_flag = CheckMouseCoords();
	};
	~MouseHoverEvent() {};

	std::unique_ptr<EventManager> event;

	bool CheckMouseCoords();

	void Sycle();


private:
	const HWND hWnd;
	const HANDLE hStdOut;
	const int delay;

	RECT rConsole;
	POINT pCursor;
	bool is_mouse_in_flag;
};

