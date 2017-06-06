#pragma once

#include "ofMain.h"
#include "Window_Manager.h"
#include "ofxColorPicker.h"

class Object
{
private:
	int m_x, m_y; //posições x e y do objeto (no editor)
	float inc = 1.0f; //incremento pra mudar cor da imagem
	float inc_s = 125.0f; //incremento pra mudar saturação

	ofVec2f m_position; //posição no jogo

	std::string m_name; //nome do objeto (é o que o usuário digitará para salvar o objeto)

	
	ofImage backup; //imagem com as cores originais

	/*Dados pra exportar do objeto*/
	bool isProtec;
	bool isHealing;
	bool isSpeed;
	bool isAttack;
	bool isTime;
	bool isLessHP;
	bool isLessSpeed;
	bool isLessAttack;
	bool isObstacle;

	int m_protection; //qtde de protecao
	int m_heal; //qtde de heal
	int m_speed; //qtde de velocidade
	int m_attack; //qtde de ataque
	int m_time; //qtded de segundos
	int m_lessHP; 
	int m_lessSpeed;
	int m_lessAttack;
	int m_obstacleHP;
	int m_amountObs;

public:
	Object(std::string path); //construtor para editor
	Object(bool protec, int protection, bool healing, int heal, bool spd, int speed, bool atk, int attack, bool time, int seconds,
		   bool lessHP, int hp, bool lessSpeed, int lessSpd, bool lessAttack, int lessAtk, bool obstacle, int obstacleHP, int amt); //construtor pro jogo
	
	~Object();

	ofImage m_image;  //imagem que representa o objeto

	void Draw();
	void Draw(ofVec2f position);

	//void Destruct(bool breakable, ofVec2f positionShot);
	void SetPosition(ofVec2f position);
	ofVec2f GetPosition();

	int GetW();
	int GetH();

	void SetX(int x);
	void SetY(int y);

	void SetProtection(bool protec, int protection);
	void SetHeal(bool healing, int heal);
	void SetSpeed(bool spd, int speed);
	void SetAttack(bool atk, int attack);
	void SetTime(bool time, int seconds);
	void SetLessHP(bool lessHP, int hp);
	void SetLessSpeed(bool lessSpeed, int lessSpd);
	void SetLessAttack(bool lessAttack, int lessAtk);
	void SetObstacle(bool obstacle, int obstacelHP, int amt);

	void PlusColor();
	void ChangeColor(ofColor color);
	float CheckHue(float hue, float n);

	void PlusSatu();
	void ChangeSatu();
};

