#include "Enemy.h"

USING_NS_CC;

cocos2d::Sprite* playerbullet1;

//보스만들기
//목숨 총알 폭탄만들기

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::init()
{
	arabian1 = Sprite::create("arabian.png");
	arabian1->setScale(3);
	arabian1->setAnchorPoint(Vec2(0, 0));
	arabian1->setPosition(Vec2(800, 100));
	arabian1->setZOrder(4);
    this->addChild(arabian1);
	arabianrunning1(arabian1);

	arabian2 = Sprite::create("arabian.png");
	arabian2->setScale(3);
	arabian2->setAnchorPoint(Vec2(0, 0));
	arabian2->setPosition(Vec2(1000, 100));
	arabian2->setZOrder(4);
	this->addChild(arabian2);
	arabianrunning2(arabian2);

	arabian3 = Sprite::create("arabian.png");
	arabian3->setScale(3);
	arabian3->setAnchorPoint(Vec2(0, 0));
	arabian3->setPosition(Vec2(1200, 100));
	arabian3->setZOrder(4);
	this->addChild(arabian3);
	arabianrunning3(arabian3);

	boss = Sprite::create("boss1.png");
	boss->setScale(3);
	boss->setAnchorPoint(Vec2(0, 0));
	boss->setPosition(Vec2(300, 250));
	boss->setZOrder(5);
	this->addChild(boss);

	leftengine = Sprite::create("leftNormal.png");
	leftengine->setAnchorPoint(Vec2(0, 0));
	leftengine->setPosition(Vec2(boss->getPositionX() + 23, boss->getPositionY() + 151));
	leftengine->setScale(3);
	leftengine->setZOrder(6);
	this->addChild(leftengine);

	auto leftengineanimation = Animation::create();
	leftengineanimation->setDelayPerUnit(0.4);
	leftengineanimation->addSpriteFrameWithFile("leftNormal.png");
	leftengineanimation->addSpriteFrameWithFile("leftRed.png");
	leftengineanimation->addSpriteFrameWithFile("leftNormal.png");
	leftengineanimation->addSpriteFrameWithFile("leftYellow.png");
	leftengineanimation->addSpriteFrameWithFile("leftNormal.png");
	leftengineanimation->addSpriteFrameWithFile("leftBlue.png");
	auto leftengineanimate = Animate::create(leftengineanimation);
	auto leftengineRep = RepeatForever::create(leftengineanimate);
	leftengine->runAction(leftengineRep);

	rightengine = Sprite::create("rightNormal.png");
	rightengine->setAnchorPoint(Vec2(0, 0));
	rightengine->setPosition(Vec2(boss->getPositionX() + 600, boss->getPositionY() + 150));
	rightengine->setScale(3);
	rightengine->setZOrder(6);
	this->addChild(rightengine);

	auto rightengineanimation = Animation::create();
	rightengineanimation->setDelayPerUnit(0.4);
	rightengineanimation->addSpriteFrameWithFile("rightNormal.png");
	rightengineanimation->addSpriteFrameWithFile("rightRed.png");
	rightengineanimation->addSpriteFrameWithFile("rightNormal.png");
	rightengineanimation->addSpriteFrameWithFile("rightYellow.png");
	rightengineanimation->addSpriteFrameWithFile("rightNormal.png");
	rightengineanimation->addSpriteFrameWithFile("rightBlue.png");
	auto rightengineanimate = Animate::create(rightengineanimation);
	auto rightengineRep = RepeatForever::create(rightengineanimate);
	rightengine->runAction(rightengineRep);

	/*auto leftsmallflame = Sprite::create("hollow.png");
	leftsmallflame->setAnchorPoint(Vec2(0, 0));
	leftsmallflame->setPosition(Vec2(boss->getPositionX() + 97, boss->getPositionY() -13));
	leftsmallflame->setScale(3);
	leftsmallflame->setZOrder(6);
	this->addChild(leftsmallflame);

	auto leftsmallflameanimation = Animation::create();
	leftsmallflameanimation->setDelayPerUnit(0.15);
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame1.png");
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame2.png");
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame3.png");
	leftsmallflameanimation->addSpriteFrameWithFile("smallflame4.png");
	auto leftsmallflameanimate = Animate::create(leftsmallflameanimation);
	auto leftsmallflameRep = RepeatForever::create(leftsmallflameanimate);
	leftsmallflame->runAction(leftsmallflameRep);

	auto rightsmallflame = Sprite::create("hollow.png");
	rightsmallflame->setFlippedX(true);
	rightsmallflame->setAnchorPoint(Vec2(0, 0));
	rightsmallflame->setPosition(Vec2(boss->getPositionX() + 623, boss->getPositionY() - 13));
	rightsmallflame->setScale(3);
	rightsmallflame->setZOrder(6);
	this->addChild(rightsmallflame);

	auto rightsmallflameanimation = Animation::create();
	rightsmallflameanimation->setDelayPerUnit(0.15);
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame1.png");
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame2.png");
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame3.png");
	rightsmallflameanimation->addSpriteFrameWithFile("smallflame4.png");
	auto rightsmallflameanimate = Animate::create(rightsmallflameanimation);
	auto rightsmallflameRep = RepeatForever::create(rightsmallflameanimate);
	rightsmallflame->runAction(rightsmallflameRep);*/

	
	auto leftflame = Sprite::create("hollow.png");
	leftflame->setAnchorPoint(Vec2(0, 0));
	leftflame->setPosition(Vec2(boss->getPositionX() + 72, boss->getPositionY() - 352));
	leftflame->setScale(3);
	leftflame->setZOrder(6);
	this->addChild(leftflame);

	auto enginefiresprite = Sprite::create("flamerow1.png");
	auto enginefiretexture = enginefiresprite->getTexture();
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.2);

	
	for (int i = 0; i < 9; i++)
	{
		animation->addSpriteFrameWithTexture(enginefiretexture, Rect( i* 50, 0, 50, 160));
	}
	
	auto animate = Animate::create(animation);
	auto rep2 = RepeatForever::create(animate);
	leftflame->runAction(rep2);


	isCollided1 = true; // 충돌 체크를 한번만 실행하기 위한 플래그 변수
	isCollided2 = true;
	isCollided3 = true;
	arabian1Alive = true;
	arabian2Alive = true;
	arabian3Alive = true;


	this->scheduleUpdate();
	return true;
}

void Enemy::update(float f)
{
	if (arabian1->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided1)
	{
		arabiandeath(arabian1,11,12);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided1 = false;
		arabian1Alive = false;
	}
	if (arabian2->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided2 )
	{
		arabiandeath(arabian2, 21, 22);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided2 = false;
		arabian2Alive = false;
	}
	if (arabian3->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided3 )
	{
		arabiandeath(arabian3, 31, 32);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided3 = false;
		arabian3Alive = false;
	}
	
}

void Enemy::arabiandeath(cocos2d::Sprite* obj,int n1,int n2)
{
	obj->stopActionByTag(n1);
	obj->stopActionByTag(n2);
	
	auto sprite1 = Sprite::create("arabianDeath.png");
	auto texture1 = sprite1->getTexture();

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.12);

	for (int i = 0; i < 2; i++)
	{
		int column = i % 11;
		animation->addSpriteFrameWithTexture(texture1, Rect(column * 48, 0, 48, 50));
	}
	for (int i = 2; i <10; i++)
	{
		int column = i % 11;
		animation->addSpriteFrameWithTexture(texture1, Rect(96+column * 58, 0, 58, 50));
	}
	
	auto animate = Animate::create(animation);
	obj->runAction(animate);
	
	
}

void Enemy::arabianrunning1(cocos2d::Sprite* obj)
{
	animation2 = Animation::create();
	animation2->setDelayPerUnit(0.12);
	animation2->addSpriteFrameWithFile("arabianRunning1.png");
	animation2->addSpriteFrameWithFile("arabianRunning2.png");
	animation2->addSpriteFrameWithFile("arabianRunning3.png");
	animation2->addSpriteFrameWithFile("arabianRunning4.png");
	animation2->addSpriteFrameWithFile("arabianRunning5.png");
	animation2->addSpriteFrameWithFile("arabianRunning6.png");
	animation2->addSpriteFrameWithFile("arabianRunning7.png");
	animation2->addSpriteFrameWithFile("arabianRunning8.png");
	animation2->addSpriteFrameWithFile("arabianRunning9.png");
	animation2->addSpriteFrameWithFile("arabianRunning10.png");
	animation2->addSpriteFrameWithFile("arabianRunning11.png");
	animation2->addSpriteFrameWithFile("arabianRunning12.png");
	
	animate2 = Animate::create(animation2);
	rep1 = RepeatForever::create(animate2);
	obj->runAction(rep1);

	pMoveBy1 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy1);
	rep1->setTag(11);
	pMoveBy1->setTag(12);
}
void Enemy::arabianrunning2(cocos2d::Sprite* obj)
{
	animation2 = Animation::create();
	animation2->setDelayPerUnit(0.12);
	animation2->addSpriteFrameWithFile("arabianRunning1.png");
	animation2->addSpriteFrameWithFile("arabianRunning2.png");
	animation2->addSpriteFrameWithFile("arabianRunning3.png");
	animation2->addSpriteFrameWithFile("arabianRunning4.png");
	animation2->addSpriteFrameWithFile("arabianRunning5.png");
	animation2->addSpriteFrameWithFile("arabianRunning6.png");
	animation2->addSpriteFrameWithFile("arabianRunning7.png");
	animation2->addSpriteFrameWithFile("arabianRunning8.png");
	animation2->addSpriteFrameWithFile("arabianRunning9.png");
	animation2->addSpriteFrameWithFile("arabianRunning10.png");
	animation2->addSpriteFrameWithFile("arabianRunning11.png");
	animation2->addSpriteFrameWithFile("arabianRunning12.png");

	animate2 = Animate::create(animation2);
	rep2 = RepeatForever::create(animate2);
	obj->runAction(rep2);

	pMoveBy2 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy2);
	rep2->setTag(21);
	pMoveBy2->setTag(22);
}
void Enemy::arabianrunning3(cocos2d::Sprite* obj)
{
	animation2 = Animation::create();
	animation2->setDelayPerUnit(0.12);
	animation2->addSpriteFrameWithFile("arabianRunning1.png");
	animation2->addSpriteFrameWithFile("arabianRunning2.png");
	animation2->addSpriteFrameWithFile("arabianRunning3.png");
	animation2->addSpriteFrameWithFile("arabianRunning4.png");
	animation2->addSpriteFrameWithFile("arabianRunning5.png");
	animation2->addSpriteFrameWithFile("arabianRunning6.png");
	animation2->addSpriteFrameWithFile("arabianRunning7.png");
	animation2->addSpriteFrameWithFile("arabianRunning8.png");
	animation2->addSpriteFrameWithFile("arabianRunning9.png");
	animation2->addSpriteFrameWithFile("arabianRunning10.png");
	animation2->addSpriteFrameWithFile("arabianRunning11.png");
	animation2->addSpriteFrameWithFile("arabianRunning12.png");

	animate2 = Animate::create(animation2);
	rep3 = RepeatForever::create(animate2);
	obj->runAction(rep3);

	pMoveBy3 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy3);
	rep3->setTag(31);
	pMoveBy3->setTag(32);
}

