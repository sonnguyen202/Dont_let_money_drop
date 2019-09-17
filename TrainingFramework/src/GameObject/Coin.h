#pragma once

#include "Sprite2D.h"

class Coin : public Sprite2D
{
public:

	Coin(std::shared_ptr<Models>& model, std::shared_ptr<Shaders>& shader, std::shared_ptr <Texture>& texture);
	
	~Coin();
	bool isActive();
	void setActive(bool status);
	void Update(float deltaTime) ;
	void setConllideSize(float size);
	float getConllideSize();
	void setDamge(float damge);
	float getDamge();	

private:
	bool m_active;
	int m_blood;
	float  m_sizeCollide;
	float m_damage;
	float m_speed;
	float m_maxspeed;


};

