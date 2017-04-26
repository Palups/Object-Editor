#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Window_Manager.h"


#define MAX_WIDTH 475
#define MAX_HEIGHT 750

class Window_Editor
{
private:
	Button *btn_cancel; //declarando bot�o CANCEL
	Button *btn_loadSprite; //declarando bot�o LOAD SPRITE
	Button *btn_changeObjectColor; //teste pra mudar a cor
	Button *btn_changeObjectSat; //teste pra mudar a satura��o
	Button *btn_saveObject; //salva o objeto criado

	Object *object; //objeto que ser� criado ao clicar em LOAD SPRITE
	UI_Slider *s_hp; //slider pra hp do objeto

	bool m_imageOnScreen; //checa se a imagem que representa o objeto est� na tela	 


	//ofxUISuperCanvas *gui; //declarando canvas

public:
	Window_Editor();
	~Window_Editor();

	void KeyPressed(int key); //testa botoes, por questao de facilitar o debug 
	void MouseReleased(int x, int y);
	void MouseDragged(int x, int y);
	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em bot�es
	void Draw();

	void SetImageOnScreen(bool imageOnScreen);
	bool GetImageOnScreen();

	string m_imgPath;
	FILE *m_file;

	//fun��es canvas

	void InputText();
};

