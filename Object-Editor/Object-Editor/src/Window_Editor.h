#pragma once

#include "ofMain.h"
#include "ofxUI.h"

#include "Window_Manager.h"

#define MAX_WIDTH 475
#define MAX_HEIGHT 750

class Window_Editor
{
private:
	Button *btn_cancel; //declarando botão CANCEL
	Button *btn_loadSprite; //declarando botão LOAD SPRITE
	Button *btn_changeObjectColor; //teste pra mudar a cor
	Button *btn_changeObjectSat; //teste pra mudar a saturação

	Object *object; //objeto que será criado ao clicar em LOAD SPRITE

	bool m_imageOnScreen; //checa se a imagem que representa o objeto está na tela

	//ofxUISuperCanvas *gui; //declarando canvas

public:
	Window_Editor();
	~Window_Editor();

	void KeyPressed(int key); //testa botoes, por questao de facilitar o debug 

	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em botões
	void Draw();

	void SetImageOnScreen(bool imageOnScreen);
	bool GetImageOnScreen();

	//funções canvas
	void exit();
	void guiEvent(ofxUIEventArgs &e);
};

