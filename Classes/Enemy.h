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

	/*void makeBullet();
	void moveBullet();*/

	
	cocos2d::Sprite* enemybullet1;

	void update(float f);

	void enemy1dead();

	bool isCollided;

private:
	
};

extern cocos2d::Sprite* enemy1;