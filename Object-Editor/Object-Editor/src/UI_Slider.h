#pragma once

#include "ofMain.h"
#include "Window_Manager.h"

class UI_Slider
{

private:
	ofRectangle r_data, r_total;
	int m_data; //Dado que o slider vai representar

	int m_x, //Coordenadas e dimensoes
		m_y,
		m_w,
		m_h;

	bool isActive;

public:
	UI_Slider(int x, int y, int w, int h, int d);
	void Draw();
	void ResetSlider(); //Reseta os valores do slider pro inicial (dados do construtor)

	void MouseClicked(int x, int y); 
	void MouseDragged(int x, int y);
	void MouseReleased(int x, int y);
	bool TestClick(int x, int y); // Testa se o click foi dentro do slider
	~UI_Slider();
};
