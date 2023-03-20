#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Homework02Answer :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Homework02Answer);

	cocos2d::Label* pLabel;
	int currentLetter;

	cocos2d::Sprite* sprite1;
	cocos2d::Sprite* sprite2;
	std::vector<cocos2d::Sprite*> vecSprite;

	cocos2d::EventListenerTouchOneByOne* listener;

	void eventupdate(float f);

	void onEnter();
	void onExit();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void doCollisionCheck(cocos2d::Sprite* target, cocos2d::Sprite* enemy);

};