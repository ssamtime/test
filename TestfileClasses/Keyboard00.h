#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Keyboard00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Keyboard00);

	void onEnter();
	void onExit();

	//키보드 콜백함수
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

private:
	cocos2d::Sprite* pSprite;
	cocos2d::EventListenerKeyboard* _listener;

	bool _left;
	bool _right;
	bool _up;
	bool _down;

	void update(float f)override;

};