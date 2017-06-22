#include "Object.h"

Object::Object(std::string path)
{
	m_image.loadImage(path);
	backup.loadImage(path);

	m_image.resize(100, 100);

	isProtec = true;
	isHealing = true;
	isSpeed = true;
	isAttack = true;
	isTime = true;
	isLessHP = true;
	isLessSpeed = true;
	isLessAttack = true;
	isObstacle = true;

	m_protection = 1000;
	m_heal = 1000;
	m_speed = 500;
	m_attack = 500;
	m_time = 500;
	m_lessHP = 1000;
	m_lessSpeed = 500;
	m_lessAttack = 500;
	m_obstacleHP = 1000;
	m_amountObs = 100;
}

Object::Object(bool protec, int protection, bool healing, int heal, bool spd, int speed, bool atk, int attack, bool time, int seconds,
			   bool lessHP, int hp, bool lessSpeed, int lessSpd, bool lessAttack, int lessAtk, bool obstacle, int obstacleHP, int amt)
{
	isProtec = protec;
	m_protection = protection;

	isHealing = healing;
	m_heal = heal;

	isSpeed = spd;
	m_speed = speed;

	isAttack = atk;
	m_attack = attack;

	isTime = time;
	m_time = seconds;

	isLessHP = lessHP;
	m_lessHP = hp;

	isLessSpeed = lessSpeed;
	m_lessSpeed = lessSpd;

	isLessAttack = lessAttack;
	m_lessAttack = lessAtk;

	isObstacle = obstacle;
	m_obstacleHP = obstacleHP;
	m_amountObs = amt;
}

Object::~Object()
{
	std::cout << "objeto deletado" << std::endl;
}

void Object::Draw()
{
	m_image.draw(m_x, m_y);
}

void Object::Draw(ofVec2f position)
{

}

/*void Object::Destruct(bool breakable, ofVec2f positionShot)
{
	if (breakable)
	{
		if (positionShot.distance(GetPosition()) <= 3)
		{
			m_hp = 0;
		}
	}
}*/

void Object::SetPosition(ofVec2f position)
{
	m_position = position;
}

ofVec2f Object::GetPosition()
{
	return m_position;
}

ofImage Object::GetImg()
{
	return m_image;
}

int Object::GetW()
{
	return m_image.getWidth();
}

int Object::GetH()
{
	return m_image.getHeight();
}

void Object::SetX(int x)
{
	m_x = x;
}

void Object::SetY(int y)
{
	m_y = y;
}

/* funções de cada slider */

void Object::SetProtection(bool protec, int protection)
{
	isProtec = protec;
	if (isProtec)
		m_protection = protection;
	else
		m_protection = 0;
}

void Object::SetHeal(bool healing, int heal)
{
	isHealing = healing;
	m_heal = heal;
}

void Object::SetSpeed(bool spd, int speed)
{
	isSpeed = spd;
	if (isSpeed)
		m_speed = speed;
	else
		m_speed = 0;
}

void Object::SetAttack(bool atk, int attack)
{
	isAttack = atk;
	if (isAttack)
		m_attack = attack;
	else
		m_attack = 0;
}

void Object::SetTime(bool time, int seconds)
{
	isTime = time;
	if (isTime)
		m_time = seconds;
	else
		m_time = 0;
}

void Object::SetLessHP(bool lessHP, int hp)
{
	isLessHP = lessHP;
	m_lessHP = hp;
}

void Object::SetLessSpeed(bool lessSpeed, int lessSpd)
{
	isLessSpeed = lessSpeed;
	if (isLessSpeed)
		m_lessSpeed = lessSpd;
	else
		m_lessSpeed = 0;
}

void Object::SetLessAttack(bool lessAttack, int lessAtk)
{
	isLessAttack = lessAttack;
	if (isLessAttack)
		m_lessAttack = lessAtk;
	else
		m_lessAttack = 0;
}

void Object::SetObstacle(bool obstacle, int obstacelHP)
{
	isObstacle = obstacle;
	if (isObstacle)
		m_obstacleHP = obstacelHP;
	else
		m_obstacleHP = 0;
		
}

void Object::SetSize(ofImage img)
{
	m_image = img;
	img.resize(100, 100);
}

/* ---------------------- */

void Object::PlusColor()
{
	inc += 1.0f;
	if (inc > 12.0f)
		inc = 0.0f;
}

void Object::ChangeColor(ofColor color)
{
	GrayImage();

	int cor = GetColor();

	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			ofColor outraColor = m_image.getColor(x, y);
			int h = outraColor.r;
			if (h == cor)
			{
				m_image.setColor(x, y, color);
			}
			
			else
			{
				ofColor maisOutraColor = backup.getColor(x, y);
				m_image.setColor(x, y, maisOutraColor);
		}

			// color.setHue(CheckHue(h, inc));
			//m_image.setColor(x, y, color);
			//m_image.setColor(x, y, boop);
			//color.a = 90.0f;
		}
	}
	m_image.update();
}
void Object::GrayImage()
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			ofColor cor = backup.getColor(x, y);

			if (cor.a == 1 && cor.getSaturation() != 100 && cor.getSaturation() != 0)
			{
				int r = cor.r;

				cor.set(r, r, r, 1.0f);
				m_image.setColor(x, y, cor);
			}
		}
	}
}

int Object::GetColor()
{
	std::vector<float> colors; //hue de cores
	std::vector<int> numbers; //numero de incidencias
	bool flag = false;

	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			ofColor cor = backup.getColor(x, y);

			if (cor.a == 1 && cor.getSaturation() != 100 && cor.getSaturation() != 0)
			{
				int r = cor.r;

				for (int i = 0; i < colors.size(); i++)
				{
					if (colors[i] == r)
					{
						numbers[i] = numbers[i] + 1;
						flag = true;
					}
				}

				if (!flag)
				{
					colors.push_back(r);
					numbers.push_back(0);
				}
			}
		}
	}
	
	//Verifica incidencia de cores no vetor de cores
	int maiorInc = 0; //maior incidencia de cor
	float corMaiorInc; //cor de maior incidencia
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] > maiorInc)
		{
			maiorInc = numbers[i];
			corMaiorInc = colors[i];
		}
	}

	return corMaiorInc;
}

float Object::CheckHue(float hue, float n)
{
	
	//float m = hue * n;
	float m = hue - n;

	if (m < 0)
		return n - hue;
	return m;

}

void Object::PlusSatu()
{
	inc_s += 25.0f;
	if (inc_s > 250.0f)
		inc_s = 50.0f;
}

void Object::ChangeSatu()
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			float s;
			ofColor color = m_image.getColor(x, y);
			if (color != 255)
			{
				color.setSaturation(inc_s);
				m_image.setColor(x, y, color);
			}
		}
	}
	m_image.update();
}
