#include "Enemy.h"

USING_NS_CC;

cocos2d::Sprite* playerbullet1;



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
	arabianrunning(arabian1);

	arabian2 = Sprite::create("arabian.png");
	arabian2->setScale(3);
	arabian2->setAnchorPoint(Vec2(0, 0));
	arabian2->setPosition(Vec2(1000, 100));
	arabian2->setZOrder(4);
	this->addChild(arabian2);
	arabianrunning(arabian2);

	arabian3 = Sprite::create("arabian.png");
	arabian3->setScale(3);
	arabian3->setAnchorPoint(Vec2(0, 0));
	arabian3->setPosition(Vec2(1200, 100));
	arabian3->setZOrder(4);
	this->addChild(arabian3);
	arabianrunning(arabian3);

	isCollided1 = true; // 충돌 체크를 한번만 실행하기 위한 플래그 변수
	isCollided2 = true;
	isCollided3 = true;



	this->scheduleUpdate();
	return true;
}

void Enemy::update(float f)
{
	if (arabian1->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided1)
	{
		arabiandeath(arabian1);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided1 = false;
	}
	if (arabian2->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided2)
	{
		arabiandeath(arabian2);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided2 = false;
	}
	if (arabian3->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided3)
	{
		arabiandeath(arabian3);
		playerbullet1->setPosition(Vec2(0, 2000));
		isCollided3 = false;
	}
	
}

void Enemy::arabiandeath(cocos2d::Sprite* obj)
{
	obj->stopAction(rep);
	obj->stopAction(pMoveBy1);

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

void Enemy::arabianrunning(cocos2d::Sprite* obj)
{
	
	auto animation2 = Animation::create();
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
	
	auto animate2 = Animate::create(animation2);
	rep = RepeatForever::create(animate2);
	obj->runAction(rep);

	pMoveBy1 = MoveBy::create(10, Vec2(-2000, 0));
	obj->runAction(pMoveBy1);
}

//rep 이랑 pMoveBy1 따로 함수만들어서 멈춰줘야할듯,, 지금 1이맞으면 3이멈춤



//
//void Enemy::makeBullet()
//{
//	enemybullet1 = Sprite::create("bullet.png");
//	enemybullet1->setAnchorPoint(Vec2(0, 0));
//
//	
//	enemybullet1->setPosition(enemy1->getPositionX() - 50 , enemy1->getPositionY() + 55);
//
//	enemybullet1->setZOrder(5);
//	moveBullet();
//
//	this->addChild(playerbullet1);
//}
//
//void Enemy::moveBullet()
//{
//    auto movebullet = MoveBy::create(0.8, Vec2( 100 ,0));
//}


