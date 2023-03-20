#include "Collision00.h"

USING_NS_CC;

Scene* Collision00::createScene()
{
	return Collision00::create();
}

bool Collision00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	pEnemy = Sprite::create("Character/cookie_woman2.png");
	pEnemy->setPosition(Vec2(800, 360));
	this->addChild(pEnemy);

	this->createCookie();
	this->scheduleUpdate();

	return true;
}

void Collision00::createCookie()
{
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Animation/spritesheet.plist");
	cocos2d::Vector<SpriteFrame*> animFrames;

	char str[100] = { 0, };
	for (int i = 0; i < 4; i++)
	{
		sprintf(str, "run0%d.png", i + 1);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	pCookie = Sprite::createWithSpriteFrameName("run01.png");
	pCookie->setPosition(Vec2(240, 360));
	this->addChild(pCookie);

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.2);
	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	pCookie->runAction(rep);

}

void Collision00::update(float f)
{
	if (pCookie == nullptr)
	{
		log("pCookie is null");
		this->createCookie();
		return;
	}

	pCookie->setPosition(Vec2(pCookie->getPositionX() + 2, pCookie->getPositionY()));
	
	if (pCookie->getBoundingBox().intersectsRect(pEnemy->getBoundingBox())) //intersect:충돌검사
	{
		log("Collision Check");
		pCookie->removeFromParentAndCleanup(true);
		pCookie = nullptr;
	}
}
