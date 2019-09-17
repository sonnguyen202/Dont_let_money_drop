#pragma once
#include "gamestatebase.h"
#include <GameButton.h>

class GSSetting :
	public GameStateBase
{
public:
	GSSetting();
	~GSSetting();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void HandleMouseEvents(int x, int y) override;

	void Update(float deltaTime);
	void Draw();

private:
	std::shared_ptr<Sprite2D> m_BackGround;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
};