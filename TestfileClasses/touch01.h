#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class touch01 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(touch01);

	cocos2d::Sprite* sprite1;
	cocos2d::Sprite* sprite2;
	cocos2d::Sprite* sprite3;
	cocos2d::EventListenerTouchOneByOne* listener;

	//화면이 보일때마다 호출되는 메서드 선언
	void onEnter();
	//화면 사라질때마다 호출되는 메서드선언
	void onExit();

	//객체들의 Z-Order를 변경할 메서드를 선언
	void reZorder(cocos2d::Sprite* pSender);

		
};