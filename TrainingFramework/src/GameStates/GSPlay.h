#pragma once
#include "gamestatebase.h"
#include "GameButton.h"

class Sprite2D;
class Sprite3D;
class Text;
class Player;
class Coin;
class Sword;

class GSPlay :
	public GameStateBase
{

private:

	std::list<std::shared_ptr<GameButton>> m_listButton;

	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Text>  m_scoreText;
	std::shared_ptr<Player> m_Player;

	std::vector<std::shared_ptr<Coin>> list_Coin;
	std::vector<std::shared_ptr<Sword>> list_Sword;
	float m_delayTime;
	void createRandomCoin();
	void createRandomeSword();

public:
	GSPlay();
	~GSPlay();

	void Init() override;
	void Exit() override;

	void Pause() override;
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);
	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void HandleMouseEvents(int x, int y) ;


	void Update(float deltaTime) override;
	void Draw() override;

	static int m_score;

	
	void SetNewPostionForBullet();



};

