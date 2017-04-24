#pragma once

#include "ofMain.h"
#include "Window_Manager.h"

class Object
{
private:
	int m_x, m_y; //posi��es x e y do objeto (no editor)

	std::string m_name; //nome do objeto (� o que o usu�rio digitar� para salvar o objeto)

	ofImage m_image; //imagem que representa o objeto

public:
	Object(std::string path);

	~Object();

	void Draw();

	int GetW();
	int GetH();

	void SetX(int x);
	void SetY(int y);

	void ChangeColor();
	float CheckHue(float hue, float n);
};

