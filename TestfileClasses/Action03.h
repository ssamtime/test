#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Action03 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Action03);

	cocos2d::Sprite* pBall;
	cocos2d::Sprite* pCookie;
	cocos2d::Sprite* pCookiewoman1;
	cocos2d::Sprite* pCookiewoman2;
	
	void doAction(Ref* pSender);
	void doActionEase();
	void doActionElastic();
	void doActionBounce();
	void doActionSpeed();

};