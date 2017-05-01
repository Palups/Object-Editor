#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

ofVec2f Projectile::GetPos()
{
	return p_pos;
}

void Projectile::SetPos(ofVec2f destination, ofVec2f limit)
{
	destination.normalize();
	p_pos += destination * 5;
}
