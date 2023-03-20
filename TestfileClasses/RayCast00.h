#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class RayCast00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(RayCast00);

	void createMyPhysicsWorld();
	void onTouchesEnded(const std::vector<cocos2d::Touch*>&touches, cocos2d::Event* event);

	bool anyRay(cocos2d::PhysicsWorld& world, const cocos2d::PhysicsRayCastInfo& info, void* data);
	cocos2d::Sprite* addNewSpriteAtPosition(cocos2d::Vec2 pos);
	void myTick(float dt);

private:
	cocos2d::PhysicsWorld* m_world;
	cocos2d::DrawNode* _node;

};