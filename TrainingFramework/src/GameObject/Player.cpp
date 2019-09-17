#include "Player.h"
#include "GameStates/GSPlay.h"

#include "GameManager/ResourceManagers.h"

Player::Player(std::shared_ptr<Models>& mod, std::shared_ptr<Shaders>& shader, std::shared_ptr<Texture>& texture)
	: Sprite2D(mod, shader, texture)
{
	m_desPosition = Vector2(0, 0);
	m_blood = 3;
	m_sizeCollide = 15; 
	m_damage = 0;
	m_speed = 400;
	m_isAlive = true;

}

Player::~Player()
{

}

void Player::Move(Vector2 pos)
{
	m_desPosition = pos;
}

void Player::Update(float deltatime)
{
	if (!m_isAlive)
		return;
	if ( m_blood <= 0)
	{
		m_isAlive = false;
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_GameOver);
		return;
	}

	Vector2 position = Get2DPosition();

	if (position.x < m_desPosition.x)
	{
		position.x += m_speed * deltatime;
	}

	if (position.x > m_desPosition.x)
	{
		position.x -= m_speed * deltatime;
	}

	Set2DPosition(position);

}


float Player::distance(Vector2 pos, Vector2 target)
{
	return sqrt((pos.x - target.x) * (pos.x - target.x) + (pos.y - target.y) * (pos.y - target.y));
}


void Player::checkConllide(std::vector<std::shared_ptr<Coin>> listCoin, std::vector<std::shared_ptr<Sword>> listSword)
{
	Vector2 position = Get2DPosition();


	for (auto coin : listCoin)
	{
		if (coin->isActive())
		{
			if (distance(position, coin->Get2DPosition()) < m_sizeCollide + coin->getConllideSize())
			{
				coin->setActive(false);
				GSPlay::m_score += 5;
			}
		}
	}


	for (auto sword : listSword)
	{
		if (sword->isActive())
		{
			if (distance(position, sword->Get2DPosition()) < m_sizeCollide + sword->getConllideSize())
			{
				sword->setActive(false);
				m_blood--;

			}
		}
	}

}


void Player::setConllideSize(float size)
{
	m_sizeCollide = size;
}
float Player::getConllideSize()
{
	return m_sizeCollide;
}

void Player::setBlood(int blood)
{
	m_blood = blood;
}

int Player::getBlood()
{
	return m_blood;
}

bool Player::isAlive()
{
	return m_isAlive;
}
