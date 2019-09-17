#include <sstream>
#include <iomanip>
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "Player.h"
#include "GSPlay.h"
#include "Coin.h"
#include "Sword.h"
#include <GameStates\GSMenu.h>

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

int GSPlay::m_score = 0;

GSPlay::GSPlay()
{
	m_delayTime = 0.2;
	m_score = 0;
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play2");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);

	// comback menu
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth - 950, 100);
	button->SetSize(100, 50);
	button->SetOnClick([] {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});

	m_listButton.push_back(button);

	//human
	texture = ResourceManagers::GetInstance()->GetTexture("Player");
	m_Player = std::make_shared<Player >(model, shader, texture);
	m_Player->Set2DPosition(screenWidth / 2, screenHeight - 160);
	m_Player->Move(Vector2(screenWidth / 2, screenHeight - 200));
	m_Player->SetSize(100, 140);
	

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_scoreText = std::make_shared< Text>(shader, font, "Score: ", TEXT_COLOR::RED, 1.0);
	m_scoreText->Set2DPosition(Vector2(5, 25));
	m_bloodText = std::make_shared< Text>(shader, font, "Blood: ", TEXT_COLOR::RED, 0.8);
	m_bloodText ->Set2DPosition(Vector2(5, 50));
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
	
}

void GSPlay::HandleMouseEvents(int x, int y)
{
	m_Player->Move(Vector2(x, y));
}


void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSPlay::Update(float deltaTime)
{
	if (m_delayTime > 0)
	{
		m_delayTime -= deltaTime;
	}
	if (m_delayTime <= 0)
	{
		int f = rand() % 2;
		if (f == 1)
			createRandomCoin();
		else createRandomeSword();

		m_delayTime = 0.2;
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	//update player
	if (m_Player->isAlive())
	{
		m_Player->Update(deltaTime);
		m_Player->checkConllide(list_Coin, list_Sword);
	}
	// update coin
	for (auto coin : list_Coin)
	{
		coin->Update(deltaTime);
	}
	// update sword
	for (auto sword : list_Sword)
	{
		sword ->Update(deltaTime);
	}

	//update score
	std::stringstream stream;
	stream << std::fixed << std::setprecision(0) << m_score;
	std::string score = "Score: " + stream.str();
	m_scoreText->setText(score);
	std::stringstream stream1;
	stream1 << std::fixed << std::setprecision(0) << m_Player-> getBlood();
	std::string blood = "Blood: " + stream1.str();
	m_bloodText->setText(blood);
}


void GSPlay::Draw()
{
	m_BackGround->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto coin : list_Coin)
		if (coin->isActive())
			coin->Draw();

	for (auto sword : list_Sword)
		if (sword->isActive())
			sword->Draw();

	
		
	m_scoreText->Draw();
	if (m_Player->isAlive())
	{
		m_Player->Draw();
	}
	m_bloodText->Draw();
	
}

void GSPlay::createRandomCoin()
{
	int num = rand() % (screenWidth -50 + 1) + 50;
	Vector2 pos;
	pos.x = num;
	pos.y = 10;
	for (auto coin : list_Coin)
	{
		if(!coin->isActive())
		{
			coin->setActive(true);
			coin->Set2DPosition(pos);
			return;
		}
	}
	
	auto mod = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Coin");

	std::shared_ptr<Coin> coin = std::make_shared<Coin>( mod, shader, texture);
	coin->Set2DPosition(pos);
	coin->SetSize(39, 52.5);
	list_Coin.push_back(coin);
}

void GSPlay::createRandomeSword()
{
	int num = rand() % ( screenWidth - 50 +1) + 50;
	Vector2 pos;
	pos.x = num;
	pos.y = 10;
	for (auto sword : list_Sword)
	{
		if (!sword->isActive())
		{
			sword->setActive(true);
			sword->Set2DPosition(pos);
			return;
		}
	}

	auto mod = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Sword");

	std::shared_ptr<Sword> sword = std::make_shared<Sword>(mod, shader, texture);
	sword->Set2DPosition(pos);
	sword->SetSize(39, 100);
	list_Sword.push_back(sword);

}



void GSPlay::SetNewPostionForBullet()
{
}