#include "Keyboard00.h"

USING_NS_CC;

Scene* Keyboard00::createScene()
{
	return Keyboard00::create();
}

bool Keyboard00::init()
{
	if (!Scene::init())
	{
		return false;
	}
	///////////////////
	auto wlayer = LayerColor::create(Color4B::WHITE);
	this->addChild(wlayer);

	//스프라이트

	pSprite = Sprite::create("Character/cookie.png");
	pSprite->setPosition(Vec2(640, 360));
	this->addChild(pSprite);

	//변수 초기화
	_left = _right = _up = _down = false;
	this -> scheduleUpdate();


	return true;
}

void Keyboard00::onEnter()
{
	Scene::onEnter();

	_listener = EventListenerKeyboard::create();

	//콜백함수 연결
	_listener->onKeyPressed = CC_CALLBACK_2(Keyboard00::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(Keyboard00::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void Keyboard00::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Scene::onExit();
}

void Keyboard00::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_A:
		_left = true;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		_right = true;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		_up = true;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		_down = true;
		break;
	}
}

void Keyboard00::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event * event)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_A:
		_left =false;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		_right = false;
		break;
	case EventKeyboard::KeyCode::KEY_W:
		_up = false;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		_down = false;
		break;
	}
}

void Keyboard00::update(float f)
{
	if (_left)
	{
		//왼쪽으로 이동
		pSprite->setPositionX(pSprite->getPositionX() - 10);
	}
	if (_right)
	{
		//왼쪽으로 이동
		pSprite->setPositionX(pSprite->getPositionX() + 10);
	}
	if (_up)
	{
		//왼쪽으로 이동
		pSprite->setPositionY(pSprite->getPositionY() + 10);
	}
	if (_down)
	{
		//왼쪽으로 이동
		pSprite->setPositionY(pSprite->getPositionY() - 10);
	}
}
