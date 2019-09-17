#pragma once
#include "Sprite2D.h"
#include "Coin.h"
#include "Sword.h"
class Player : public Sprite2D
{
private:
	Vector2 m_desPosition;
	int m_blood;
	float  m_sizeCollide;
	float m_damage;
	float m_speed;
	bool m_isAlive;

	float distance(Vector2 position, Vector2 destination);

public:
	Player(std::shared_ptr<Models>& model, std::shared_ptr<Shaders>& shader, std::shared_ptr <Texture>& texture);
	~Player();

	void Move(Vector2 position);


	void Update(float deltaTime) override;
	void checkConllide(std::vector < std::shared_ptr < Coin>> listCoin, std::vector< std::shared_ptr <Sword>> listSword);
	void setConllideSize(float size);
	float getConllideSize();
	void setBlood(int blood);
	int getBlood();
	bool isAlive();

		

};


