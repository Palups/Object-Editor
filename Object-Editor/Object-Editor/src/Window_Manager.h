#pragma once

#include "ofMain.h"
#include "Button.h"
#include "Object.h"

//tamanho de tela
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

//estados
#define WINDOW_MENU 0
#define WINDOW_EDITOR 1

class Window_Manager
{
private:
	int m_state; //estado em que o editor se encontra (menu ou edição de objeto)

	//ofFile m_file;

public:
	Window_Manager(int state); //passando o estado como parâmetro para o programa saber em que estado começar
	~Window_Manager();

	int GetState(); //pegar estado
	void SetState(int state); //setar estado

};

