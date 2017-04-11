#include "Object.h"

Object::Object(std::string path)
{
	m_image.loadImage(path);
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
