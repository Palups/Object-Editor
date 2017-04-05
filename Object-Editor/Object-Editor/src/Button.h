#pragma once

#include "ofMain.h"

class Button
{
private:
	int m_x, m_y; //posi��es x e y do bot�o
	int m_w, m_h; //largura e altura do bot�o

	ofImage m_image; //imagem do bot�o

public:
	Button(int x, int y, int w, int h, std::string path); //para criar bot�o: posi��o x e y, largura e altura, caminho da imagem
	~Button();

	void Draw();
	bool TestClick(int x, int y); //testa se o click foi dentro do bot�o
};

