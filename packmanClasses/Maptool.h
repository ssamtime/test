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


	//�� Ŭ�� ����
	void DoClick(Ref* pSender);
	//������Ʈ ����
	void CreateObject(std::string fileName, Coordinate objPos);
	//�������� �ε��Ѵ�.
	void LoadObjectData();
	//������ �������� ���̺��Ѵ�.
	void SaveObjectData();
	//���� �������� ������Ʈ�� �����Ѵ�.
	void DoChangeCurObjectState(Ref* pSender);
	//���� �ε������� �������� ���� ������Ʈ���� �ҷ��� �����Ѵ�.
	void SetpositionObject();

};