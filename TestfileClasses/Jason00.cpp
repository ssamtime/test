#include "Json00.h"

USING_NS_CC;

Scene* Json00::createScene()
{
	return Json00::create();
}

bool Json00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	return true;
}
