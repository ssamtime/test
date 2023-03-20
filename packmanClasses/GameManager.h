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

	// ���� �Ŵ��� ���� �Լ�
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
	// ������
	std::vector<cocos2d::Sprite*> vecCandy;
	// �÷��̾�
	std::vector<Player*> vecPlayer;
	// ��
	std::vector<Enemy*> vecEnemy;
	// ��
	std::vector<cocos2d::Sprite*> vecWall;

	int candyCount = 0;

	void MoveTime(float f);
	void GameOver();

	void IsEatingCandy();
	bool IsEnemyCollision();
};
