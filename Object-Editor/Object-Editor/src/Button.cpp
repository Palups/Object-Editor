#include "Button.h"

Button::Button(int x, int y, int w, int h, std::string path)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_image.loadImage(path);
}

Button::~Button()
{
}

void Button::Draw()
{
	m_image.draw(m_x, m_y);
}

bool Button::TestClick(int x, int y)
{
	if (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h) { //se o click do mouse foi dentro do botão, retorna verdadeiro
		//std::cout << "cricou no grande boto" << std::endl;
		return true;
	}
	else
		return false;
}
