#include "UI_Slider.h"

UI_Slider::UI_Slider(int x, int y, int w, int h, int d)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	m_data = d;
	isActive = false;

	ResetSlider();
}



void UI_Slider::Draw()
{
	ofSetColor(15, 190, 190);
	ofDrawRectangle(r_data);
	ofSetColor(15, 130, 130);
	ofDrawRectangle(r_total);
}

void UI_Slider::ResetSlider()
{
	r_data.x = m_x;
	r_data.y = m_y;
	r_data.width = m_w;
	r_data.height = m_h;
	

	r_total.x = m_x;
	r_total.y = m_y;
	r_total.width = m_w;
	r_total.height = m_h;
}

void UI_Slider::MouseClicked(int x, int y)
{
	if (TestClick(x, y))
		isActive = true;
}

void UI_Slider::MouseDragged(int x, int y)
{
	if (isActive)
	{
		int aux_x = x - r_data.x;
		if (aux_x < 0)
			aux_x = 0;
		r_data.setWidth(aux_x);

		//m_data = m_data * (aux_x / m_w);
	}
}

void UI_Slider::MouseReleased(int x, int y)
{
	if (isActive)
	{
		isActive = false;
		m_data = m_data * (r_data.width / m_w);
	}


	std::cout << m_data << std::endl;
}

bool UI_Slider::TestClick(int x, int y)
{
	if (x >= m_x && x <= m_x + m_w &&
		y >= m_y && y <= m_y + m_h)
	{
		return true;
	}
	
	return false;
}

UI_Slider::~UI_Slider()
{
}
