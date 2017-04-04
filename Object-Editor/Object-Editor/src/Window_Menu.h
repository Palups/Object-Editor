#pragma once

#include "ofMain.h"
#include "Button.h"
#include "Window_Manager.h"

class Window_Menu
{
private:
	Button *btn_new;
public:
	Window_Menu();
	~Window_Menu();

	void MousePressed(int x, int y, Window_Manager *window_manager);
	void Update();
	void Draw();
};

