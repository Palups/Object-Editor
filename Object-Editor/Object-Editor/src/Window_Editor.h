#pragma once

#include "ofMain.h"
#include "Window_Manager.h"

class Window_Editor
{
private:
	Button *btn_cancel; //declarando botão CANCEL
	Button *btn_loadSprite; //declarando botão LOAD SPRITE
public:
	Window_Editor();
	~Window_Editor();

	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em botões
	void Draw();
};

