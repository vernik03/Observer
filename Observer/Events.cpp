#include "Events.h"
bool MouseHoverEvent::CheckMouseCoords() {
	GetCursorPos(&pCursor);
	ScreenToClient(hWnd, &pCursor);
	GetClientRect(hWnd, &rConsole);
	return ((pCursor.x < rConsole.right&& pCursor.x > 0) &&
		(pCursor.y < rConsole.bottom&& pCursor.y > 0));
}

void MouseHoverEvent::Sycle() {
	while (true)
	{
		if (is_mouse_in_flag != CheckMouseCoords())
		{
			is_mouse_in_flag = !is_mouse_in_flag;
			event->Notify(is_mouse_in_flag);
		}

		Sleep(200);
	}
}