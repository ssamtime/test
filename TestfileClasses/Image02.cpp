#include "Image02.h"

USING_NS_CC;

Scene*Image02::createScene()
{
	return Image02::create();
}

bool Image02::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto wlayer = LayerColor::create(Color4B::WHITE);
	//auto wlayer = setVisible(false);
	this->addChild(wlayer);
	
	auto parent = Sprite::create("Character/cookie.png");
	parent->setPosition(Vec2(1000, 200));
	this->addChild(parent);

	auto child = Sprite::create("white-512x512.png");
	child->setTextureRect(Rect(0, 0, 150, 10));
	child->setColor(Color3B::RED);

	//이미지 사이즈를 받아온다.
	Size parentSize = parent->getContentSize();
	child->setPosition(Vec2(parentSize.width / 2, parentSize.height + 10));

	parent->addChild(child);


	return true;
}