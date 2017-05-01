#include "Object.h"

Object::Object(std::string path)
{
	m_image.loadImage(path);
	backup.loadImage(path);

	isDestructable = true;
	isPushable = true;
	isHealing = true;
	isDamaging = true;

	m_hp = 1000;
	m_kg = 1000;
	m_heal = 500;
	m_dmg = 500;
}

Object::Object(bool healing, int heal, bool breakable, int hp, bool damaging, int dmg, bool pushable, int kg)
{
	isHealing = healing;
	m_heal = heal;
	isDestructable = breakable;
	m_hp = hp;
	isDamaging = damaging;
	m_dmg = dmg;
	isPushable = pushable;
	m_kg = kg;
}

Object::~Object()
{
	std::cout << "objeto deletado" << std::endl;
}

void Object::Draw()
{
	m_image.draw(m_x, m_y);
}

void Object::Destruct(bool breakable, ofVec2f positionShot)
{
	if (breakable)
	{
		if (positionShot.distance(GetPosition()) <= 3)
		{
			m_hp = 0;
		}
	}
}

void Object::SetPosition(ofVec2f position)
{
	m_position = position;
}

ofVec2f Object::GetPosition()
{
	return m_position;
}

int Object::GetW()
{
	return m_image.getWidth();
}

int Object::GetH()
{
	return m_image.getHeight();
}

void Object::SetX(int x)
{
	m_x = x;
}

void Object::SetY(int y)
{
	m_y = y;
}

void Object::SetHp(bool destructable, int hp)
{
	isDestructable = destructable;
	if (isDestructable) // I.e. o objeto é destrutivel
		m_hp = hp;
	else
		m_hp = 0;
}

void Object::SetKg(bool pushable, int kg)
{
	isPushable = pushable;
	m_kg = kg;
}

void Object::SetHeal(bool healing, int heal)
{
	isHealing = healing;
	m_heal = heal;
}

void Object::SetDamage(bool damaging, int dmg)
{
	isDamaging = damaging;
	m_dmg = dmg;
	std::cout << "meep dmg:" + ofToString(isDamaging) + " - " + ofToString(m_dmg) << std::endl;

}

void Object::PlusColor()
{
	inc += 1.0f;
	if (inc > 12.0f)
		inc = 0.0f;
}

void Object::ChangeColor()
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			float h;
			ofColor color = backup.getColor(x, y);
			h = color.getHue();
			color.setHue(CheckHue(h, inc));
			m_image.setColor(x, y, color);
		}
	}
	m_image.update();
}

float Object::CheckHue(float hue, float n)
{
	float m = hue * n;
	
	if (m < 0)
		return 0;
	if (m > 360)
		return 360;
	return m;
}

void Object::PlusSatu()
{
	inc_s += 25.0f;
	if (inc_s > 250.0f)
		inc_s = 50.0f;
}


void Object::ChangeSatu()
{
	for (int y = 0; y < m_image.getHeight(); y++)
	{
		for (int x = 0; x < m_image.getWidth(); x++)
		{
			float s;
			ofColor color = m_image.getColor(x, y);
			if (color != 255)
			{
				color.setSaturation(inc_s);
				m_image.setColor(x, y, color);
			}
		}
	}
	m_image.update();
}
