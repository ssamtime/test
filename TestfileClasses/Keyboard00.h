#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
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

	//Ű���� �ݹ��Լ�
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