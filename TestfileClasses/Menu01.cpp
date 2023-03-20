#include "Menu01.h"

USING_NS_CC;

Scene* Menu01::createScene()
{
	return Menu01::create();
}

bool Menu01::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	auto pMenuItem1 = MenuItemImage::create("Button/btn-play-normal.png", "Button/btn-play-selected.png",
		CC_CALLBACK_1(Menu01::doClick1, this));

	auto pMenuItem2 = MenuItemImage::create("Button/btn-play-normal.png", "Button/btn-play-selected.png",
		CC_CALLBACK_1(Menu01::doClick2, this));

	auto pMenuItem3 = MenuItemImage::create("Button/btn-play-normal.png", "Button/btn-play-selected.png",
		CC_CALLBACK_1(Menu01::doClick3, this));

	auto pMenu = Menu::create(pMenuItem1, pMenuItem2, pMenuItem3, nullptr);

	pMenu->alignItemsVertically();
	this->addChild(pMenu);


	return true;
}

void Menu01::doClick1(Ref * pSender)
{
	log("Clicked 1");
}

void Menu01::doClick2(Ref * pSender)
{
	log("Clicked 2");
}

void Menu01::doClick3(Ref * pSender)
{
	log("Clicked 3");
}
