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
	if (inc > 5.0f)
		inc = 5.0f;
}

void Object::SubColor()
{
	inc -= 1.0f;
	if (inc < 0.0f)
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
			std::cout << "boop" << std::endl;
		}
	}
	m_image.update();
	std::cout << "meep" << std::endl;
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
