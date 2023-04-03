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
	enemy1 = Sprite::create("arabian.png");
    enemy1->setScale(3);
    enemy1->setAnchorPoint(Vec2(0, 0));
    enemy1->setPosition(Vec2(400, 100));
    enemy1->setZOrder(4);
    
    this->addChild(enemy1);

	this->scheduleUpdate();

	return true;
}

void Enemy::update(float f)
{
	if (enemy1->getBoundingBox().intersectsRect(playerbullet1->getBoundingBox()))
	{
		log("Collision! ");
	}
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


