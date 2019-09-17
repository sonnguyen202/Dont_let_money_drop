#include "GameStates/GSPlay.h"
#include <Application.h>
#include "Player.h"
#include <Sword.h>


Sword::Sword(std::shared_ptr<Models>& mod, std::shared_ptr<Shaders>& shader, std::shared_ptr<Texture>& texture)
	: Sprite2D(mod, shader, texture)
{
	m_active = false;
	m_blood = 3;
	m_sizeCollide = 15;
	m_damage = 5;
	m_speed = 200;
	m_maxspeed = 500;
	m_timeContinue = 0.0;
	m_maxTimeCointinue = 10.0;

}

Sword::~Sword() {
}

bool Sword::isActive() {
	return m_active;
}

void Sword::setActive(bool status) {
	m_active = status;
	m_blood = 3;
}


void Sword::Update(float deltaTime)
{
	//if (!m_active) 
	//	return;


	Vector2 position = Get2DPosition();
	position.y = position.y + m_speed * deltaTime;
	Set2DPosition(position);

	

}

void Sword::setDamge(float damage) {
	m_damage = damage;
}

float Sword::getDamge() {
	return m_damage;
}

void Sword::setConllideSize(float size) {
	m_sizeCollide = size;
}

float Sword::getConllideSize() {
	return m_sizeCollide;
}


