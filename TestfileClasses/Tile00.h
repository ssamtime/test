#pragma once
#include "cocos2d.h"

//UTF-8 : 전세계모든 문자표현할수있도록 만든 규약. 안하면 한글 깨짐
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

class Tile00 :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Tile00);

	cocos2d::Size winSize;
	cocos2d::Vec2 dragonPosition;
	cocos2d::Sprite* dragon;
	cocos2d::TMXTiledMap* tmap;
	cocos2d::TMXLayer* background;
	cocos2d::TMXLayer* items;
	cocos2d::TMXLayer* metainfo;

	cocos2d::EventListenerTouchOneByOne* listener;

	void onEnter();
	void onExit();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void createDragon();
	void setViewPointCenter(cocos2d::Vec2 position);
	cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);
	void setPlayerPosition(cocos2d::Vec2 position);

};