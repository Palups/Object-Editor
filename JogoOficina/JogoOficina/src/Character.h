#pragma once
#include <ofVec2f.h>

class Character
{
public:
	Character();
	~Character();

	ofVec2f GetPos();
	void SetPos(ofVec2f destination, ofVec2f limit);

protected:
	ofVec2f c_pos;
};