#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class touch02 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(touch02);

	cocos2d::Sprite* pCookie;
	cocos2d::EventListenerTouchAllAtOnce* listener;

	void onEnter();
	void onExit();
	
	//터치가 시작할때 발생하는 이벤트
	void onTouchBegan(const std::vector<cocos2d::Touch*>&touches, cocos2d::Event* event);
	//터치가 이동할때 발생하는 이벤트
	void onTouchMoved(const std::vector<cocos2d::Touch*>&touches, cocos2d::Event* event);
	//터치가 끝날때 발생하는 이벤트
	void onTouchEnded(const std::vector<cocos2d::Touch*>&touches, cocos2d::Event* event);
	//터치가 취소되었을때 발생하는 이벤트
	void onTouchCancelled(const std::vector<cocos2d::Touch*>&touches, cocos2d::Event* event);


};