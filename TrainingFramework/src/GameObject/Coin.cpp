#include "GameStates/GSPlay.h"
#include "GameManager/ResourceManagers.h"
#include "Player.h"
#include <Coin.h>

Coin::Coin (std::shared_ptr<Models>& mod, std::shared_ptr<Shaders>& shader, std::shared_ptr<Texture>& texture)
	: Sprite2D(mod, shader, texture)
{
	m_active = false;
	m_blood = 3;
	m_sizeCollide = 20;
	m_damage = 5;
	m_speed = 200;
	m_maxspeed = 500;

}

Coin::~Coin() {
}

bool Coin::isActive() {
	return m_active;
}


void Coin::Update(float deltaTime)
{

	Vector2 position = Get2DPosition();
	if (GSPlay::m_score <= 50)
	{
		position.y = position.y + m_speed * deltaTime;
	}
	if (GSPlay::m_score > 50 && GSPlay::m_score <= 100) {
		position.y = position.y +( m_speed * 2) * deltaTime;
	}
	if (GSPlay::m_score > 100 && GSPlay::m_score <= 200) {
		position.y = position.y + (m_speed * 3) * deltaTime;

	}
	if (GSPlay::m_score > 200 && GSPlay::m_score<= 500)
	{
		position.y = position.y + (m_speed * 4) * deltaTime;

	}
	if (GSPlay::m_score > 500)
	{
		position.y = position.y + (m_speed * 5) * deltaTime;

	}
	Set2DPosition(position);
}

void Coin::setDamge(float damage) {
	m_damage = damage;
}

float Coin::getDamge() {
	return m_damage;
}

void Coin::setConllideSize(float size) {
	m_sizeCollide = size;
}

float Coin::getConllideSize() {
	return m_sizeCollide;
}

void Coin::setActive(bool status) {
	m_active = status;
	m_blood = 3;
}




