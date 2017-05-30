#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxGui.h"
#include "Window_Manager.h"
#include "ofxColorPicker.h"


#define MAX_WIDTH 475
#define MAX_HEIGHT 750

class Window_Editor
{
private:
	Button *btn_cancel; //declarando botão CANCEL
	Button *btn_loadSprite; //declarando botão LOAD SPRITE
	Button *btn_changeObjectColor; //teste pra mudar a cor
	Button *btn_changeObjectSat; //teste pra mudar a saturação
	Button *btn_saveObject; //salva o objeto criado

	Object *object; //objeto que será criado ao clicar em LOAD SPRITE

	/*User interface -- Atributos*/
	UI_Switch *sw_breakable; //switch pra objeto destrutivel
	UI_Slider *s_hp; //slider pra hp do objeto

	UI_Switch *sw_pushable; //objeto empurravel
	UI_Slider *s_kg; //slider pro peso do objeto

	UI_Switch *sw_healing; //objeto que da heal
	UI_Slider *s_heal; //slide pro heal

	UI_Switch *sw_damaging; //objeto que da dmg
	UI_Slider *s_dmg;

	bool m_imageOnScreen; //checa se a imagem que representa o objeto está na tela	
	string input;


public:
	Window_Editor();
	~Window_Editor();

	void KeyPressed(int key); //testa botoes, por questao de facilitar o debug 
	void MouseReleased(int x, int y);
	void MouseDragged(int x, int y);
	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em botões
	void Draw();
	void Update();

	void SetImageOnScreen(bool imageOnScreen);
	bool GetImageOnScreen();

	void InputText();

	string m_imgPath;
	ofstream m_file;

	//funções canvas
	void exit();
	void guiEvent(ofxUIEventArgs &e);

	ofColor boop;

	/* Paleta de cores */
	ofxColorPicker colorPicker;
	ofMesh meshGradient;
};

