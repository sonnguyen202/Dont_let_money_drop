#include "GameStates/GSPlay.h"
#include <Application.h>
#include "Player.h"
#include <Coin.h>

Coin::Coin (std::shared_ptr<Models>& mod, std::shared_ptr<Shaders>& shader, std::shared_ptr<Texture>& texture)
	: Sprite2D(mod, shader, texture)
{
	m_active = false;
	m_blood = 3;
	m_sizecollide = 15;
	m_damage = 5;
	m_speed = 200;
	m_maxspeed = 500;
	m_timeContinue = 0;
	m_maxTimeCointinue = 10;

}

Coin::~Coin() {
}

bool Coin::isActive() {
	return m_active;
}

void Coin::setActive(bool status) {
	m_active = status;
	m_blood = 3;
}


void Coin::Update(float deltaTime)
{
	if (!m_active)
		return;

	if (m_timeContinue > 0)
	{
		m_timeContinue = m_timeContinue - deltaTime;
	}

	Vector2 position = Get2DPosition();
	position.y = position.y + m_speed * deltaTime;
	Set2DPosition(position);

}

void Coin::setDamge(float damage) {
	m_damage = damage;
}

float Coin::getDamge() {
	return m_damage;
}

void Coin::setConllideSize(float size) {
	m_sizecollide = size;
}

float Coin::getConllideSize() {
	return m_sizecollide;
}

float  Coin::distance(Vector2 position, Vector2 destination) {

	return sqrt((position.x - destination.x) * (position.x - destination.x) + (position.y - destination.y) * (position.y - destination.y));

}
