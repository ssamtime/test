#pragma once
//��ũ�� ��� ���ο� ������ �������� �¿�� ��ũ���� �� �ִ� Ŭ�����̴�.
//Cocos2d-x���� ��ũ�Ѻ� Ŭ������ Ȯ�� Ŭ�����̴�.

#include "cocos2d.h"
#include "ui/CocosGUI.h"


//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class ScrollView00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(ScrollView00);

	//��ũ�Ѻ信 ������� �Է¿� ���� �̺�Ʈ�� �߻��ϸ�, �̺�Ʈ���� ó���ϱ����� �޼��带 �����Ѵ�.
	void scrollEvent(Ref* pSender, cocos2d::ui::ScrollView::EventType event);

};