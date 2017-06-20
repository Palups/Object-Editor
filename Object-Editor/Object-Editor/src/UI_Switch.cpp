#include "UI_Switch.h"



UI_Switch::UI_Switch(int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;

	status = true;
	image_on.loadImage("images/swt_on.png");
	image_off.loadImage("images/swt_off.png");
	image_status = image_off;

	label = "";
}

void UI_Switch::SetLabel(std::string name)
{
	label = name;
}

bool UI_Switch::GetStatus()
{
	return status;
}

bool UI_Switch::TestClick(int x, int y) //Testa o click do mouse
{
	if (x >= m_x && x <= m_x + m_w &&
		y >= m_y && y <= m_y + m_h)
		return true;
	return false;
}
 
void UI_Switch::Draw() //Desenha	
{
	image_status.draw(m_x, m_y, m_w, m_h);
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(label, m_x, m_y - 5);
	ofSetColor(255);
}

void UI_Switch::MouseClicked(int x, int y) //Chama no mouseclicked 
{
	ClickSwitch();
}

void UI_Switch::ClickSwitch() //Muda o estado do switch
{
	status = !status;
	if (status) //Está ligado
	{
		image_status = image_on;
		image_status.update();
	}
	else //Está desligado
	{
		image_status = image_off;
		image_status.update();
	}
}


UI_Switch::~UI_Switch()
{
}
