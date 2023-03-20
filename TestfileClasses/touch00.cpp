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

	//싱글터치 모드로 터치 리스너 등록
	listener = EventListenerTouchOneByOne::create();

	//터치 이벤트 처리 모드를 지정한다.
	//이 경우 오브젝트가 겹쳐 있을 경우, Z-Order가 제일높은 객체가 터치 이벤트를 혼자 수신한다.
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(touch00::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(touch00::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(touch00::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(touch00::onTouchCancelled, this);

	//이벤트 디스패처에 싱글터치 이벤트를 등록한다.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

void touch00::onExit()
{
	//필요없을때 제거해준다.
	//Scene::onExit(); 함수 윗줄에 해줘야댐
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();

}

bool touch00::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	auto touchPoint = touch->getLocation();

	//스프라이트 위치한 좌표를 기준으로 크기
	//범위(Rect)를 가져온다.(getBoundingBox)
	//스프라이트의 Rect범위 안에 터치한 좌표가 있는지 검사한다(containsPoint)
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
