#include "Button.h"

Button::Button(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}


Button::~Button()
{
}

void Button::Draw()
{
	ofSetColor(0, 0, 0, 0);
	ofDrawRectangle(m_x, m_y, m_w, m_h);
}

bool Button::TestClick(int x, int y)
{
	if (x >= m_x && x <= m_x + m_w && y >= m_y && y <= m_y + m_h)
		return true;
	return false;
}
