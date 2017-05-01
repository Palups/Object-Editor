#pragma once
#include <ofVec2f.h>

class Projectile
{
public:
	Projectile();
	~Projectile();

	ofVec2f GetPos();
	void SetPos(ofVec2f destination, ofVec2f limit);

protected:
	ofVec2f p_pos;

private:

};
