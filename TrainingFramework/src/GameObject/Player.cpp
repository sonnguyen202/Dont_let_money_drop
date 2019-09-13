#include "Player.h"
#include "GameStates/GSPlay.h"

#include "GameManager/ResourceManagers.h"

Player::Player(std::shared_ptr<Models>& mod, std::shared_ptr<Shaders>& shader, std::shared_ptr<Texture>& texture)
	: Sprite2D(mod, shader, texture)
{
	m_position = Vector2(1, 0);
	bool m_active = false;
	int m_blood = 3;
	float  m_sizecollide;
	float m_damage;
	float m_speed;
	float m_maxspeed;
	float m_timeContinue;
	float m_maxTimeContinue;

}

Player::~Player()
{

}

void Player::Move(Vector2 pos)
{
	m_position = pos;
}

void Player::Update(float deltatime)
{

}


float Player::distance(Vector2 pos, Vector2 target)
{
	return sqrt((pos.x - target.x) * (pos.x - target.x) + (pos.y - target.y) * (pos.y - target.y));
}


void Player::checkConllide(std::vector<std::shared_ptr<Coin>> listCoin, std::vector<std::shared_ptr<Sword>> listSword)
{

}


void Player::setConllideSize(float size)
{
	m_sizecollide = size;
}
float Player::getConllideSize()
{
	return m_sizecollide;
}

void Player::setBlood(int blood)
{
	m_blood = blood;
}

int Player::getBlood()
{
	return m_blood;
}

bool Player::isLive()
{
	return m_active;
}
