#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif



class Menu01 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Menu01);

	void doClick1(Ref* pSender); //ref�վ�� �Լ� �����ͷ� �ѱ���ճ�
	void doClick2(Ref* pSender);
	void doClick3(Ref* pSender);
};