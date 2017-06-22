#pragma once
#include "ofMain.h"

class UI_Switch
{
private:
	int m_x,
		m_y,
		m_w,
		m_h;

	bool status;

	ofImage 
		image_status,
		image_on, 
		image_off;

	std::string label;

public:
	UI_Switch(int x, int y, int w, int h);
	void Draw();
	void ResetSwitch();
	void MouseClicked(int x, int y);

	void SetLabel(std::string name);
	bool GetStatus();
	bool TestClick(int x, int y);
	void ClickSwitch();
	~UI_Switch();
};

