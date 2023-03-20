#pragma once
#include "cocos2d.h"

class Image02 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Image02);
};