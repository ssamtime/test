#include "Schedule02.h"

USING_NS_CC;

Scene* Schedule02::createScene()
{
	return Schedule02::create();
}

bool Schedule02::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);


	auto pMenuItem1 = MenuItemFont::create("Pause", CC_CALLBACK_1(Schedule02::doClick, this));
	pMenuItem1->setColor(Color3B::BLACK);
	
	auto pMenuItem2 = MenuItemFont::create("Resume", CC_CALLBACK_1(Schedule02::doClick, this));
	pMenuItem2->setColor(Color3B::BLACK);
	
	pMenuItem1->setTag(1);
	pMenuItem2->setTag(2);

	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, nullptr);
	pMenu->alignItemsVertically();
	this->addChild(pMenu);
	

	auto pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(140, 200));
	this->addChild(pCookie);

	auto myActionForward = MoveBy::create(2, Vec2(200, 0));
	auto myActionBackward = myActionForward->reverse();
	auto myAction = Sequence::create(myActionForward, myActionBackward, nullptr);
	auto rep = RepeatForever::create(myAction);

	pCookie->runAction(rep);

	return true;
}

void Schedule02::doClick(Ref * pSender)
{
	auto tItem = (MenuItem*)pSender;
	int i = tItem->getTag();

	if (i == 1)
	{
		Director::getInstance()->pause();
	}
	else
	{
		Director::getInstance()->resume();
	}
}

