#include "Object.h"

Object::Object(std::string path)
{
	m_image.loadImage(path);
	backup.loadImage(path);
}

Object::~Object()
{
	std::cout << "objeto deletado" << std::endl;
}

void Object::Draw()
{
	m_image.draw(m_x, m_y);
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

void Object::PlusColor() //Incrementa a variavel que mexe com o hue
{
	inc_h += 0.5f;
	if (inc_h > 5.0f)
		inc_h = 0.1f;
}

void Object::SubColor() //Decrementa a variavel que mexe com hue
{
	inc_h -= 0.5f;
	if (inc_h < 0.1f)
		inc_h = 0.1f;
}

void Object::ChangeColor() //Muda o hue
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			float h;
			ofColor color = backup.getColor(x, y);
			if (color != 255)
			{
				h = color.getHue();
				color.setHue(CheckHue(h, inc_h));
				m_image.setColor(x, y, color);
				std::cout << "boop" << std::endl;
			}
		}
	}
	m_image.update();
	std::cout << "meep" << std::endl;
}



float Object::CheckHue(float hue, float n) //Nao deixa o valor do hue estrapolar 
{
	float m = hue * n;
	
	if (m < 0)
		return 0;
	if (m > 255)
		return 255;
	return m;
}

void Object::PlusSatu()
{
	inc_s += 25.0f;
	if (inc_s > 150.0f)
		inc_s = 50.0f;
}

void Object::SubSatu()
{
	inc_s -= 25.0f;
	if (inc_s < 50.0f)
		inc_s = 150.0f;
}

void Object::ChangeSatu()
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			float s;
			ofColor color = backup.getColor(x, y);
			if (color != 255)
			{
				//s = color.getSaturation();
				color.setSaturation(inc_s);
				m_image.setColor(x, y, color);
				std::cout << "boop" << std::endl;
			}
		}
	}
	m_image.update();
	std::cout << "meep" << std::endl;
}
