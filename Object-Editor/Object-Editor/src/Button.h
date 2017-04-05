#pragma once

#include "ofMain.h"

class Button
{
private:
	int m_x, m_y; //posições x e y do botão
	int m_w, m_h; //largura e altura do botão

	ofImage m_image; //imagem do botão

public:
	Button(int x, int y, int w, int h, std::string path); //para criar botão: posição x e y, largura e altura, caminho da imagem
	~Button();

	void Draw();
	bool TestClick(int x, int y); //testa se o click foi dentro do botão
};

