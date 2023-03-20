#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif



class Menu01 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Menu01);

	void doClick1(Ref* pSender); //ref잇어야 함수 포인터로 넘길수잇나
	void doClick2(Ref* pSender);
	void doClick3(Ref* pSender);
};