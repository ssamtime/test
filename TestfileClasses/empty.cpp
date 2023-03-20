#include "empty.h"

USING_NS_CC;

Scene* empty::createScene()
{
	return empty::create();
}

bool empty::init()
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
