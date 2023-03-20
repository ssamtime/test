#pragma once
#include "cocos2d.h"
#include "stdafx.h"
#include "StartScene.h"


class Maptool :public::cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Maptool);

	/////////////////////////////////
	int nMap[MAP_HEIGHT][MAP_WIDTH];

	//cocos2d::EventListenerTouchOneByOne* listener;
	cocos2d::EventListenerTouchOneByOne* listener;
	std::vector<cocos2d::EventListenerTouchOneByOne*> vectEventListener;
	std::vector<cocos2d::Sprite*> _vectSprite;

	std::string curObject;
	MapObject curState = MapObject::CANDY;

	void onEnter();
	void onExit();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event*event);


	//맵 클릭 여부
	void DoClick(Ref* pSender);
	//오브젝트 생성
	void CreateObject(std::string fileName, Coordinate objPos);
	//맵정보를 로드한다.
	void LoadObjectData();
	//세팅한 맵정보를 세이브한다.
	void SaveObjectData();
	//현재 세팅중인 오브젝트를 변경한다.
	void DoChangeCurObjectState(Ref* pSender);
	//맵을 로드했을때 맵정보에 따라 오브젝트들을 불러와 세팅한다.
	void SetpositionObject();

};