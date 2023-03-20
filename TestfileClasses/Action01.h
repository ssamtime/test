#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif



class Action01 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Action01);

	cocos2d::Sprite* pCookie;
	cocos2d::Sprite* pCookieGirl;

	void doAction(Ref* pSender);
	void doActionMove();
	void doActionBezier();
	void doActionJump();
	void doActionRotate();
	void doActionTint();
	void doActionPlace();

	void doActionScale();
	void doActionBlink();
	void doActionShow();
	void doActionFadeInOut();

};