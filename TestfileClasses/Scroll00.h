#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
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
	
	//������ȯ ���� ��ư
	//������ ���� ���������� ���� �ֵ��� �� ���⺰�� �ΰ��� �����

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