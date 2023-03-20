#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Schedule01 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Schedule01);
	
	int nNum;
	bool bChange;

	void doStart(Ref *pSender);
	void doPause(Ref* pSender);
	void doResume(Ref* pSender);
	void doChange(Ref* pSender);
	void doStop(Ref* pSender);
	void tick1(float f);
	void tick2(float f);


};