#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

ofVec2f Character::GetPos()
{
	return c_pos;
}

void Character::SetPos(ofVec2f destination, ofVec2f limit)
{
	destination.normalize();
	c_pos += destination;

	if (c_pos.x > limit.x)
		c_pos.x = limit.x;
	if (c_pos.x < 0)
		c_pos.x = 0;
	if (c_pos.y > limit.y)
		c_pos.y = limit.y;
	if (c_pos.y < 0)
		c_pos.y = 0;
}
