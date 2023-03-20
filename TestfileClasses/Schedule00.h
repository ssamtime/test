#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Schedule00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Schedule00);

	int nNum;

	void callEveryFrame(float f);
	void myTick(float f);
	void myTickOnce(float f);
	void update(float delta) override;

};