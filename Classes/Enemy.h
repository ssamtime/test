#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "Player.h"
#include "Weapon.h"
#include "audio/include/AudioEngine.h"

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

	bool bossidle;

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

	cocos2d::Action* leftflamesequence;
	cocos2d::Action* rightflamesequence;
	cocos2d::Action* rightengineRep;
	cocos2d::Action* leftengineRep;
	cocos2d::Action* bossmoverepforever;
	cocos2d::Action* bossmoverepforever2;

	cocos2d::Sprite* enemybullet1;
	cocos2d::Sprite* leftsmallflame;
	cocos2d::Sprite* rightsmallflame;

	int soundId7;

	void update(float f);

	void arabiandeath(cocos2d::Sprite* obj, int n1, int n2);
	void arabianrunning1(cocos2d::Sprite* obj);
	void arabianrunning2(cocos2d::Sprite* obj);
	void arabianrunning3(cocos2d::Sprite* obj);
	
	void bombfire(cocos2d::Sprite *object);
	void AnimationCallback();
	void onAnimationEnded();
};

extern cocos2d::Sprite* arabian1;
extern cocos2d::Sprite* arabian2;
extern cocos2d::Sprite* arabian3;
extern cocos2d::Sprite* boss;
extern cocos2d::Sprite* leftengine;
extern cocos2d::Sprite* rightengine;
extern cocos2d::Sprite* leftflame;
extern cocos2d::Sprite* rightflame;

extern bool arabian1Alive;
extern bool arabian2Alive;
extern bool arabian3Alive;
extern bool enterbossstage;
extern int bosshp;