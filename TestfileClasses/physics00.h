//Cocos2d�� ���������� ������ 2������ �ִ�.
//1. Ĩ��ũ
//2. Box2D
//�Ѵ� ����� ����ؼ� ������ ��� x
//�̹����� Ĩ��ũ�� ����غ��ڴ�.

#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class physics00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(physics00);

	//sceneWorld��� �̸����� �����͸� ����
	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();
	
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void addNewSpriteAtPosition(cocos2d::Vec2 pos);


};