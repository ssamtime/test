#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Action02 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Action02);

	cocos2d::Sprite* pCookie;
	cocos2d::Sprite* pBG1;
	cocos2d::Sprite* pBG2;

	void doAction(Ref* pSender);
	void ActionSequence();
	void ActionSpawn();
	void ActionRepeat();
	void ActionRepeatForever();
	void ActionDelayTime();

	void Actionscroll();

	

};