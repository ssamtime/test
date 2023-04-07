#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "Player.h"
#include "Weapon.h"



class Enemy : public cocos2d::Layer
{
public:
	Enemy();
	~Enemy();

	virtual bool init();

	CREATE_FUNC(Enemy);

	bool isCollided1;
	bool isCollided2;
	bool isCollided3;

	cocos2d::Action* rep;
	cocos2d::Action* pMoveBy1;

	/*void makeBullet();
	void moveBullet();*/

	cocos2d::Sprite* enemybullet1;

	void update(float f);

	void arabiandeath(cocos2d::Sprite* obj);
	void arabianrunning(cocos2d::Sprite* obj);

	

};

extern cocos2d::Sprite* arabian1;
extern cocos2d::Sprite* arabian2;
extern cocos2d::Sprite* arabian3;