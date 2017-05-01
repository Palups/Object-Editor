#pragma once

#include "ofMain.h"
//#include "Window_Manager.h"

class ObjectJogo
{
private:
	int m_x, m_y; //posições x e y do objeto (no editor)
	float inc = 1.0f; //incremento pra mudar cor da imagem
	float inc_s = 125.0f; //incremento pra mudar saturação

	ofVec2f m_position; //posição no jogo

	std::string m_name; //nome do objeto (é o que o usuário digitará para salvar o objeto)

	
	ofImage backup; //imagem com as cores originais

	/*Dados pra exportar do objeto*/
	bool isDestructable;
	bool isPushable;
	bool isHealing;
	bool isDamaging;

	bool onScreen;

	int m_hp; //hp do objeto *destrutivel*
	int m_kg; //peso do objeto *empurravel*
	int m_heal; //qdade de heal *healable*
	int m_dmg; //qdade de dmg *damaging*

public:
	ObjectJogo(std::string path); //construtor para editor
	ObjectJogo(std::string path, bool healing, int heal, bool breakable, int hp,
		bool damaging, int dmg, bool pushable, int kg); //construtor pro jogo
	

	~ObjectJogo();

	ofImage m_image;  //imagem que representa o objeto

	void Draw();
	void Draw(ofVec2f position);

	bool Destruct(bool breakable, ofVec2f positionShot);
	void SetPosition(ofVec2f position);
	ofVec2f GetPosition();
	bool GetOnScreen();

	int GetW();
	int GetH();

	void SetX(int x);
	void SetY(int y);

	void SetHp(bool destructable, int hp);
	void SetKg(bool pushable, int kg);
	void SetHeal(bool healing, int heal);
	void SetDamage(bool damaging, int dmg);

	void PlusColor();
	void ChangeColor();
	float CheckHue(float hue, float n);

	void PlusSatu();
	void ChangeSatu();
};

