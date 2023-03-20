#include "Animation00.h"

USING_NS_CC;

Scene* Animation00::createScene()
{
	return Animation00::create();
}

bool Animation00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);
	//////////////////////
	//background
	pBackground1 = Sprite::create("Background/land.png");
	this->addChild(pBackground1);
	pBackground1->setLocalZOrder(1);
	pBackground1->setAnchorPoint(Vec2(0, 0));

	pBackground2 = Sprite::create("Background/land.png");
	this->addChild(pBackground2);
	pBackground2->setLocalZOrder(1);
	pBackground2->setAnchorPoint(Vec2(0, 0));
	pBackground2->setPosition(Vec2(1963, 0));



	//pcookie
	auto pCookie = Sprite::create("Animation/run01.png");
	pCookie->setPosition(Vec2(200, 200));
	pCookie->setLocalZOrder(2);
	this->addChild(pCookie);

	auto animation = Animation::create();

	//이미지 돌아가는 speed
	animation->setDelayPerUnit(0.12);

	animation->addSpriteFrameWithFile("Animation/run01.png");
	animation->addSpriteFrameWithFile("Animation/run02.png");
	animation->addSpriteFrameWithFile("Animation/run03.png");
	animation->addSpriteFrameWithFile("Animation/run04.png");

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);

	pCookie->runAction(rep);

	doAction();
	

	return true;
}

void Animation00::doAction()
{
	auto pMoveBy1 = MoveBy::create(4, Vec2(-1963, 0));
	auto pPlace1 = Place::create(Vec2(0, 0));
	auto pSequence1 = Sequence::create(pMoveBy1, pPlace1, nullptr);
	auto rep1 = RepeatForever::create(pSequence1);
	pBackground1->runAction(rep1);

	auto pMoveBy2 = MoveBy::create(4, Vec2(-1963, 0));
	auto pPlace2 = Place::create(Vec2(1963, 0));
	auto pSequence2 = Sequence::create(pMoveBy2, pPlace2, nullptr);
	auto rep2 = RepeatForever::create(pSequence2);
	pBackground2->runAction(rep2);

}
