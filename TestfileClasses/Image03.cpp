#include "Image03.h"

USING_NS_CC;

Scene* Image03::createScene()
{
	return Image03::create();
}

bool Image03::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	auto lolipopwoman = Sprite::create("Character/cookie_woman2.png");
	lolipopwoman->setPosition(400, 400);
	//lolipopwoman->setGlobalZOrder(3);
	this->addChild(lolipopwoman);


	auto hpbar = Sprite::create("white-512x512.png");
	hpbar->setTextureRect(Rect(0,0,150,10));
	hpbar->setColor(Color3B::RED);

	Size lolipopwomanSize = lolipopwoman->getContentSize();
	hpbar->setPosition(Vec2(lolipopwomanSize.width/2 , lolipopwomanSize.height + 10));

	//hpbar->setZOrder(0);
	lolipopwoman->addChild(hpbar);

	return true;
}