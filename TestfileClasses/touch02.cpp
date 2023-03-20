#include "touch02.h"

USING_NS_CC;

Scene* touch02::createScene()
{
	return touch02::create();
}

bool touch02::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	pCookie = Sprite::create("Character/cookie.png");
	pCookie->setPosition(Vec2(640, 360));
	this->addChild(pCookie);





	return true;

}

void touch02::onEnter()
{
	Scene::onEnter();

	listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(touch02::onTouchBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(touch02::onTouchMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(touch02::onTouchEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(touch02::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void touch02::onExit()
{
	_eventDispatcher->removeEventListener(listener);
	
	Scene::onExit();
}

void touch02::onTouchBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();
	
	bool bTouch = pCookie->getBoundingBox().containsPoint(touchPoint);

	if (bTouch)
	{
		log("Sprite clicked,,");
	}

	/*
	//������� for��
	������ for�ݺ����� �޸�, �������� ������ �˷����� �ʾƵ� �˾Ƽ� ó������ ������ ��ȸ�ϴ� �ݺ���

	for(������Ÿ�� elem::������ ����Ʈ)
	{
		����
		elem ����ϸ��
	}
	*/
	/*
		for(auto &item:touches)
		{
			auto touch=item;
			auto touchPoint = touch->getLocation();

			log("onTocuhesBegan id= %d,x=%f,y=%f",touch->getID(),touchPoint.x,touchPoint.y);
		}
	*/
}

void touch02::onTouchMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();

	log("onTouchMove id=%d,x=%f,y=%f", touch->getID(), touchPoint.x, touchPoint.y);
}

void touch02::onTouchEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	auto touch = touches[0];
	auto touchPoint = touch->getLocation();

	log("onTouchEnded id=%d,x=%f,y=%f", touch->getID(), touchPoint.x, touchPoint.y);
}

void touch02::onTouchCancelled(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event)
{
	
}
