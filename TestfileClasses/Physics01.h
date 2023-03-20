#pragma once
#include "cocos2d.h"

//UTF-8 : �������� ����ǥ���Ҽ��ֵ��� ���� �Ծ�. ���ϸ� �ѱ� ����
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Physics01 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Physics01);

	//-----------------------------Physics----------------------------
	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicalWorld();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	//���� �ٸ� ��ü�� ����������
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	/*
	���δٸ� ��ü�� �����ϱ� ������ ��
	bool onContactPreSolve(cocos2d::PhysicsContact&contact) 
	*/
	/*
	���δٸ� ��ü�� �������� ������ ��
	void onTontactPostSolve(cocos2d::PhysicsContact&contact);
	*/
	/*
	void onContactSeparate(cocos2d::PhysicsContact& contact,this)
	*/

	void addNewSpriteAtPosition(cocos2d::Vec2 pos);

};