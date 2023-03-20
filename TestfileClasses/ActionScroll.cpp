#include "ActionScroll.h"

USING_NS_CC;

Scene* ActionScroll::createScene()
{
	return ActionScroll::create();
}

bool ActionScroll::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////

	pBackground1 =Sprite::create("Background/land.png");
	this->addChild(pBackground1);
	pBackground1->setAnchorPoint(Vec2(0, 0));

	pBackground2 = Sprite::create("Background/land.png");
	this->addChild(pBackground2);
	pBackground2->setAnchorPoint(Vec2(0, 0));
	pBackground2->setPosition(Vec2(1963, 0));

	doAction();


	return true;
}

void ActionScroll::doAction()
{
	auto pMoveBy = MoveBy::create(4, Vec2(-1963, 0));
	auto pPlace = Place::create(Vec2(0, 0));
	auto pSequence = Sequence::create(pMoveBy, pPlace, nullptr);
	auto rep = RepeatForever::create(pSequence);
	pBackground1->runAction(rep);

	auto pMoveBy2 = MoveBy::create(4, Vec2(-1963, 0));
	auto pPlace2 = Place::create(Vec2(1963, 0));
	auto pSequence2 = Sequence::create(pMoveBy2, pPlace2, nullptr);
	auto rep2 = RepeatForever::create(pSequence2);
	pBackground2->runAction(rep2);
}