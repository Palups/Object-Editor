#pragma once

#include "ofMain.h"
#include "Button.h"
#include "Object.h"
#include "UI_Slider.h"
#include "UI_Switch.h"

//tamanho de tela
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

//estados
#define WINDOW_MENU 0
#define WINDOW_EDITOR 1

class Window_Manager
{
private:
	int m_state; //estado em que o editor se encontra (menu ou edi��o de objeto)

	

public:
	Window_Manager(int state); //passando o estado como par�metro para o programa saber em que estado come�ar
	~Window_Manager();

	//FILE* GetFile();

	int GetState(); //pegar estado
	void SetState(int state); //setar estado

};

