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

void Object::PlusColor()
{
	inc += 1.0f;
	if (inc > 12.0f)
		inc = 0.0f;
}

void Object::ChangeColor()
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			float h;
			ofColor color = backup.getColor(x, y);
			h = color.getHue();
			color.setHue(CheckHue(h, inc));
			m_image.setColor(x, y, color);
		}
	}
	m_image.update();
}

float Object::CheckHue(float hue, float n)
{
	float m = hue * n;
	
	if (m < 0)
		return 0;
	if (m > 360)
		return 360;
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
			if (color.getBrightness() < 220)
			{
				color.setSaturation(inc_s);
				m_image.setColor(x, y, color);
			}
		}
	}
	m_image.update();
}

