#pragma once
#include "Projectile.h"
#include <ofVec2f.h>

class HeroBullet: 
	public Projectile
{
public:
	HeroBullet();
	HeroBullet(ofVec2f pos);
	~HeroBullet();

private:

};
