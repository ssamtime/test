#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class scroll00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(scroll00);

	cocos2d::Layer* layer1;
	cocos2d::Layer* layer2;
	
	cocos2d::Sprite* dragon;
	
	//방향전환 쓰일 버튼
	//눌리기 전과 눌렀을때에 쓸수 있도록 각 방향별로 두개씩 만든다

	cocos2d::Sprite* rightSprite;
	cocos2d::Sprite* rightPressedSprite;
	cocos2d::Sprite* leftSprite;
	cocos2d::Sprite* leftPressedSprite;

	cocos2d::Size winSize;
	cocos2d::EventListenerTouchOneByOne* listener;

	bool isLeftPressed;
	bool isRightPressed;

	void createBackground();
	void createDragon();
	void createArrowButtons();

	void onEnter();
	void onExit();
	void onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* evnet);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* evnet);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* evnet);

	bool isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch);
	void startMovingBackground();
	void stopMovingBackground();
	void moveBackground(float t);

};