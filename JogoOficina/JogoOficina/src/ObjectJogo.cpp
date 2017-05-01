#include "ObjectJogo.h"

ObjectJogo::ObjectJogo(std::string path)
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

ObjectJogo::ObjectJogo(std::string path,bool healing, int heal, bool breakable, int hp, bool damaging, int dmg, bool pushable, int kg)
{
	m_image.loadImage(path);
	isHealing = healing;
	m_heal = heal;
	isDestructable = breakable;
	m_hp = hp;
	isDamaging = damaging;
	m_dmg = dmg;
	isPushable = pushable;
	m_kg = kg;
	onScreen = true;
}

ObjectJogo::~ObjectJogo()
{
	std::cout << "objeto deletado" << std::endl;
}

void ObjectJogo::Draw()
{
	m_image.draw(m_x, m_y);
}

void ObjectJogo::Draw(ofVec2f position)
{
	if(onScreen)
		m_image.draw(position);
}

bool ObjectJogo::Destruct(bool breakable, ofVec2f positionShot)
{
	if (breakable && onScreen)
	{
		if (positionShot.x <= (m_image.getWidth() + m_position.x) && positionShot.x >= m_position.x &&
			positionShot.y <= (m_image.getHeight() + m_position.y) && positionShot.y >= m_position.y)
		{
			m_hp = 0;
			onScreen = false;
			cout << "destruiu o objeto" << endl;
			return true;			
		}
		else
			return false;
		/*if (positionShot.distance(GetPosition()) <= 3)
		{
			m_hp = 0;
			cout << "acertou o objeto" << endl;
		}*/
	}
}

void ObjectJogo::SetPosition(ofVec2f position)
{
	m_position = position;
}

ofVec2f ObjectJogo::GetPosition()
{
	return m_position;
}

bool ObjectJogo::GetOnScreen()
{
	return onScreen;
}

int ObjectJogo::GetW()
{
	return m_image.getWidth();
}

int ObjectJogo::GetH()
{
	return m_image.getHeight();
}

void ObjectJogo::SetX(int x)
{
	m_x = x;
}

void ObjectJogo::SetY(int y)
{
	m_y = y;
}

void ObjectJogo::SetHp(bool destructable, int hp)
{
	isDestructable = destructable;
	if (isDestructable) // I.e. o objeto é destrutivel
		m_hp = hp;
	else
		m_hp = 0;
}

void ObjectJogo::SetKg(bool pushable, int kg)
{
	isPushable = pushable;
	m_kg = kg;
}

void ObjectJogo::SetHeal(bool healing, int heal)
{
	isHealing = healing;
	m_heal = heal;
}

void ObjectJogo::SetDamage(bool damaging, int dmg)
{
	isDamaging = damaging;
	m_dmg = dmg;
	std::cout << "meep dmg:" + ofToString(isDamaging) + " - " + ofToString(m_dmg) << std::endl;

}

void ObjectJogo::PlusColor()
{
	inc += 1.0f;
	if (inc > 12.0f)
		inc = 0.0f;
}

void ObjectJogo::ChangeColor()
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

float ObjectJogo::CheckHue(float hue, float n)
{
	float m = hue * n;
	
	if (m < 0)
		return 0;
	if (m > 360)
		return 360;
	return m;
}

void ObjectJogo::PlusSatu()
{
	inc_s += 25.0f;
	if (inc_s > 250.0f)
		inc_s = 50.0f;
}


void ObjectJogo::ChangeSatu()
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
