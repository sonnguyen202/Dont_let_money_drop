#include "GSHelp.h"


extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine



GSHelp::GSHelp()
{
}

GSHelp::~GSHelp()
{
}

void GSHelp::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_help");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	//home button
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(screenWidth / 2, 100);
	button->SetSize(200, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		});
	m_listButton.push_back(button);
}

void GSHelp::Exit()
{
}

void GSHelp::Pause()
{
}

void GSHelp::Resume()
{
}

void GSHelp::HandleEvents()
{
}

void GSHelp::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSHelp::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto it : m_listButton)
	{
		(it)->HandleTouchEvents(x, y, bIsPressed);
		if ((it)->IsHandle()) break;
	}
}

void GSHelp::HandleMouseEvents(int x, int y)
{
}

void GSHelp::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSHelp::Draw()
{
	m_BackGround->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
