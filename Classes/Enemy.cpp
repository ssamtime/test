#include "Enemy.h"

USING_NS_CC;

cocos2d::Sprite* playerbullet1;

int i;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::init()
{
	enemy1 = Sprite::create("arabian.png");
    enemy1->setScale(3);
    enemy1->setAnchorPoint(Vec2(0, 0));
    enemy1->setPosition(Vec2(400, 100));
    enemy1->setZOrder(4);
    
    this->addChild(enemy1);

	this->scheduleUpdate();

	isCollided = true; // 충돌 체크를 한번만 실행하기 위한 플래그 변수

	return true;
}

void Enemy::update(float f)
{
	if (enemy1->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()) && isCollided)
	{
		enemy1dead();
		isCollided = false;
	}
}

void Enemy::enemy1dead()
{
	auto sprite1 = Sprite::create("arabianDeath.png");
	auto texture1 = sprite1->getTexture();

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.12);

	for (i = 0; i < 2; i++)
	{
		int column = i % 11;
		animation->addSpriteFrameWithTexture(texture1, Rect(column * 48, 0, 48, 50));
	}
	for (i = 0; i <10; i++)
	{
		int column = i % 11;
		animation->addSpriteFrameWithTexture(texture1, Rect(96+column * 58, 0, 58, 50));
	}
	
	auto animate = Animate::create(animation);
	auto delay = DelayTime::create(3.0);
	auto sequence = Sequence::create(animate, delay, nullptr);
	enemy1->runAction(sequence);
	
}



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


