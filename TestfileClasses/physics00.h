//Cocos2d의 물리엔진의 종류는 2가지가 있다.
//1. 칩멍크
//2. Box2D
//둘다 기능은 비슷해서 뭘쓰든 상관 x
//이번에는 칩멍크를 사용해보겠다.

#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class physics00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(physics00);

	//sceneWorld라는 이름으로 포인터를 설정
	cocos2d::PhysicsWorld* m_world;
	void createMyPhysicsWorld();
	
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void addNewSpriteAtPosition(cocos2d::Vec2 pos);


};