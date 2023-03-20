#include "cocos2d.h"
#include "stdafx.h"
#include "singleton.h"
#include "Player.h"
#include "Enemy.h"

class GameManager : public cocos2d::Layer, public singletonBase<GameManager>
{
public:
	GameManager();
	~GameManager();

	cocos2d::Node* _listener;
	cocos2d::SEL_CallFunc _selector;

	// 게임 매니저 생성 함수
	static GameManager* create(cocos2d::Node* _listener, 
		cocos2d::SEL_CallFunc _selector);
	virtual bool init(cocos2d::Node* _listener, cocos2d::SEL_CallFunc _selector);


	cocos2d::Sprite* bg;
	bool isGameEnd = false;
	int nMap[MAP_HEIGHT][MAP_WIDTH];

	void FileDataRead();
	void EnemyCallback();
	void SetPlayerPosition();
	void SetPositionObject();

	Coordinate GetPlayerPos();

private:
	// 아이템
	std::vector<cocos2d::Sprite*> vecCandy;
	// 플레이어
	std::vector<Player*> vecPlayer;
	// 적
	std::vector<Enemy*> vecEnemy;
	// 벽
	std::vector<cocos2d::Sprite*> vecWall;

	int candyCount = 0;

	void MoveTime(float f);
	void GameOver();

	void IsEatingCandy();
	bool IsEnemyCollision();
};
