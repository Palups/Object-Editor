#pragma once

#include "ofMain.h"

#define WINDOW_MENU 0

class Window_Manager
{
private:
	int m_state;
public:
	Window_Manager();
	~Window_Manager();

	int GetState();
	void SetState(int state);

	void Draw();

};

