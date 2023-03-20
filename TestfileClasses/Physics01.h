#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
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

	//서로 다른 물체가 접촉했을때
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	/*
	서로다른 물체가 접촉하기 직전일 때
	bool onContactPreSolve(cocos2d::PhysicsContact&contact) 
	*/
	/*
	서로다른 물체가 떨어지기 직전일 때
	void onTontactPostSolve(cocos2d::PhysicsContact&contact);
	*/
	/*
	void onContactSeparate(cocos2d::PhysicsContact& contact,this)
	*/

	void addNewSpriteAtPosition(cocos2d::Vec2 pos);

};