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

	bool m_imageOnScreen; //checa se a imagem que representa o objeto est� na tela
	int m_sliderControl; //define quais sliders ser�o mostrados - 1 = buffs / 2 = debuffs / 3 = obst�culos

	string input;

	Button *btn_cancel; //declarando bot�o CANCEL
	Button *btn_loadSprite; //declarando bot�o LOAD SPRITE
	Button *btn_changeObjectColor; //teste pra mudar a cor
	//Button *btn_changeObjectSat; //teste pra mudar a satura��o
	Button *btn_saveObject; //salva o objeto criado
	Button *btn_changeSliders; //altera os sliders que aparecem

	Object *object; //objeto que ser� criado ao clicar em LOAD SPRITE

	/* -- User interface -- Atributos -- */
	// -- Buffs
	UI_Switch *sw_protection; //objeto que da prote��o
	UI_Slider *s_protection;

	UI_Switch *sw_healing; //objeto que da heal
	UI_Slider *s_heal;

	UI_Switch *sw_speed; //objeto que da velocidade
	UI_Slider *s_speed;

	UI_Switch *sw_attack; //objeto que aumenta ataque
	UI_Slider *s_attack;

	UI_Switch *sw_time; //objeto que diminui tempo
	UI_Slider *s_time;


	// -- Debuffs
	UI_Switch *sw_lessHP; //objeto que tira vida
	UI_Slider *s_lessHP;

	UI_Switch *sw_lessSpeed; //objeto que tira velocidade
	UI_Slider *s_lessSpeed;

	UI_Switch *sw_lessAttack; //objeto que tira ataque
	UI_Slider *s_lessAttack;


	// -- Obst�culos
	UI_Switch *sw_obstacle; //objeto fixo
	UI_Slider *s_obstacleHP;
	UI_Slider *s_obs;

public:
	Window_Editor();
	~Window_Editor();

	void KeyPressed(int key); //testa botoes, por questao de facilitar o debug 
	void MouseReleased(int x, int y);
	void MouseDragged(int x, int y);
	void MousePressed(int x, int y, Window_Manager *window_manager); //faz o TestClick em bot�es
	void Draw();
	void Update();

	void SetImageOnScreen(bool imageOnScreen);
	bool GetImageOnScreen();

	int GetSliderControl();

	void InputText();

	string m_imgPath;
	ofstream m_file;

	//fun��es canvas
	void exit();
	void guiEvent(ofxUIEventArgs &e);

	ofColor boop;

	/* Paleta de cores */
	ofxColorPicker colorPicker;
	ofMesh meshGradient;
};

