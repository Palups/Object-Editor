#pragma once

#include "ofMain.h"
#include "Window_Manager.h"

class Window_Editor
{
private:
	Button *btn_cancel; //declarando bot�o CANCEL
public:
	Window_Editor();
	~Window_Editor();

	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em bot�es
	void Draw();
};

