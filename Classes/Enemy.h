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
	

	cocos2d::Animate* leftflameanimate1;
	cocos2d::Animate* leftsmallflameanimate;
	cocos2d::Animate* leftflameanimate2;
	cocos2d::Animate* leftflameanimate3;
	cocos2d::Animate* leftflameanimate4;
	cocos2d::Animate* leftflameanimate5;
	cocos2d::Animate* leftflameanimate6;

	cocos2d::Animate* rightflameanimate1;
	cocos2d::Animate* rightsmallflameanimate;
	cocos2d::Animate* rightflameanimate2;
	cocos2d::Animate* rightflameanimate3;
	cocos2d::Animate* rightflameanimate4;
	cocos2d::Animate* rightflameanimate5;
	cocos2d::Animate* rightflameanimate6;

	cocos2d::Animation* animation2;
	cocos2d::ActionInterval* animate2;

	cocos2d::Action* rep1;
	cocos2d::Action* pMoveBy1;
	cocos2d::Action* rep2;
	cocos2d::Action* pMoveBy2;
	cocos2d::Action* rep3;
	cocos2d::Action* pMoveBy3;


	cocos2d::Sprite* enemybullet1;
	cocos2d::Sprite* leftflame;
	cocos2d::Sprite* rightflame;
	cocos2d::Sprite* leftsmallflame;
	cocos2d::Sprite* rightsmallflame;

	void update(float f);

	void arabiandeath(cocos2d::Sprite* obj, int n1, int n2);
	void arabianrunning1(cocos2d::Sprite* obj);
	void arabianrunning2(cocos2d::Sprite* obj);
	void arabianrunning3(cocos2d::Sprite* obj);
	

	void AnimationCallback();
	
};

extern cocos2d::Sprite* arabian1;
extern cocos2d::Sprite* arabian2;
extern cocos2d::Sprite* arabian3;
extern cocos2d::Sprite* boss;
extern cocos2d::Sprite* leftengine;
extern cocos2d::Sprite* rightengine;

extern bool arabian1Alive;
extern bool arabian2Alive;
extern bool arabian3Alive;
