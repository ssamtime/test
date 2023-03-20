#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
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

	//ȭ���� ���϶����� ȣ��Ǵ� �޼��� ����
	void onEnter();
	//ȭ�� ����������� ȣ��Ǵ� �޼��弱��
	void onExit();

	//��ü���� Z-Order�� ������ �޼��带 ����
	void reZorder(cocos2d::Sprite* pSender);

		
};