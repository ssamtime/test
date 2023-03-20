#include "touch00.h"

USING_NS_CC;

Scene* touch00::createScene()
{
	return touch00::create();
}

bool touch00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(640, 360);
	this->addChild(pCookie);




	return true;
}

void touch00::onEnter()
{
	Scene::onEnter();

	//�̱���ġ ���� ��ġ ������ ���
	listener = EventListenerTouchOneByOne::create();

	//��ġ �̺�Ʈ ó�� ��带 �����Ѵ�.
	//�� ��� ������Ʈ�� ���� ���� ���, Z-Order�� ���ϳ��� ��ü�� ��ġ �̺�Ʈ�� ȥ�� �����Ѵ�.
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(touch00::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(touch00::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(touch00::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(touch00::onTouchCancelled, this);

	//�̺�Ʈ ����ó�� �̱���ġ �̺�Ʈ�� ����Ѵ�.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void touch00::onExit()
{
	//�ʿ������ �������ش�.
	//Scene::onExit(); �Լ� ���ٿ� ����ߴ�
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();

}

bool touch00::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();

	//��������Ʈ ��ġ�� ��ǥ�� �������� ũ��
	//����(Rect)�� �����´�.(getBoundingBox)
	//��������Ʈ�� Rect���� �ȿ� ��ġ�� ��ǥ�� �ִ��� �˻��Ѵ�(containsPoint)
	bool bTouch = pCookie->getBoundingBox().containsPoint(touchPoint);

	if (bTouch)
	{
		log("Sprite clicked,,,");
	}
	return true;
}

void touch00::onTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchMoved id=%d, x=%f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);

}

void touch00::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchEnded id=%d, x=%f, y=%f", touch->getID(), touchPoint.x, touchPoint.y);
}

void touch00::onTouchCancelled(cocos2d::Touch * touch, cocos2d::Event * event)
{
}
