#pragma once

#include "ofMain.h"

class Button
{
private:
	int m_x, m_y;
	int m_w, m_h;

public:
	Button(int x, int y, int w, int h);
	~Button();

	void Draw();
	bool TestClick(int x, int y);
};

