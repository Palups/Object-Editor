#pragma once

#include "ofMain.h"
#include "Window_Manager.h"

class Object
{
private:
	int m_x, m_y; //posições x e y do objeto (no editor)
	float inc = 1.0f; //incremento pra mudar cor da imagem
	float inc_s = 125.0f; //incremento pra mudar saturação

	std::string m_name; //nome do objeto (é o que o usuário digitará para salvar o objeto)

	ofImage m_image; //imagem que representa o objeto
	ofImage backup; //imagem com as cores originais

public:
	Object(std::string path);

	~Object();

	void Draw();

	int GetW();
	int GetH();

	void SetX(int x);
	void SetY(int y);

	void PlusColor();
	void ChangeColor();
	float CheckHue(float hue, float n);

	void PlusSatu();
	void ChangeSatu();
};

