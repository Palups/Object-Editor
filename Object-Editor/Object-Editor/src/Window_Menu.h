#pragma once

#include "ofMain.h"
#include "Window_Manager.h"

class Window_Menu
{
private:
	Button *btn_newObject; //bot�o para criar novo objeto
public:
	Window_Menu();
	~Window_Menu();

	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em bot�es
	void Draw();
};

