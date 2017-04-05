#pragma once

#include "ofMain.h"
#include "Button.h"

#define WINDOW_MENU 0

class Window_Manager
{
private:
	int m_state; //estado em que o editor se encontra (menu ou edi��o de objeto)
public:
	Window_Manager(int state); //passando o estado como par�metro para o programa saber em que estado come�ar
	~Window_Manager();

	int GetState(); //pegar estado
	void SetState(int state); //setar estado

};

