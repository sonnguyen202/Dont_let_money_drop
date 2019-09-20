#include "GameStates/GSPlay.h"
#include "GameManager/ResourceManagers.h"
#include "Player.h"
#include <Cloud.h>

Cloud::Cloud(std::shared_ptr<Models>& mod, std::shared_ptr<Shaders>& shader, std::shared_ptr<Texture>& texture)
	: Sprite2D(mod, shader, texture)
{
	m_active = false;
	m_blood = 3;
	m_sizeCollide = 20;
	m_damage = 5;
	m_speed = 50;
	m_maxspeed = 500;

}

Cloud::~Cloud() {
}

bool Cloud::isActive() {
	return m_active;
}


void Cloud::Update(float deltaTime)
{

	Vector2 position = Get2DPosition();
	position.x = position.x + m_speed * deltaTime;
	Set2DPosition(position);

}

void Cloud::setDamge(float damage) {
	m_damage = damage;
}

float Cloud::getDamge() {
	return m_damage;
}

void Cloud::setConllideSize(float size) {
	m_sizeCollide = size;
}

float Cloud::getConllideSize() {
	return m_sizeCollide;
}

void Cloud::setActive(bool status) {
	m_active = status;
	m_blood = 3;
}
