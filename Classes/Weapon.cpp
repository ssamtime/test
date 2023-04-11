
#include "Player.h"

USING_NS_CC;

cocos2d::Sprite* player;
bool _left;
bool _right;
bool _up;
bool RIGHT;
float upPressedTime;



Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

bool Weapon::init()
{
    
	_pressA = _pressD = false;

	sign = 1;

	playerbullet1 = Sprite::create("bullet.png");
	playerbullet1->setAnchorPoint(Vec2(0, 0));
	playerbullet1->setPosition(player->getPositionX()  , player->getPositionY() + -1000);
	playerbullet1->setZOrder(5);
	this->addChild(playerbullet1);

	machinegunCapsule = Sprite::create("machinegunCapsule.png");
	machinegunCapsule->setAnchorPoint(Vec2(0, 0));
	machinegunCapsule->setPosition(Vec2(1600, 100));
	machinegunCapsule->setZOrder(6);
	machinegunCapsule->setScale(3);
	this->addChild(machinegunCapsule);

	isMachinegun = false;

	this->scheduleUpdate();
	return true;
}

void Weapon::onEnter()
{
	Layer::onEnter();

	_listener = EventListenerKeyboard::create();

	//콜백함수 연결
	_listener->onKeyPressed = CC_CALLBACK_2(Weapon::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(Weapon::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void Weapon::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Layer::onExit();
}

void Weapon::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (keycode)
	{
	
	case EventKeyboard::KeyCode::KEY_A:
		if (!isMachinegun)
		{
			makeBullet();
		}
		else
		{
			makeMachinegun();
		}
		_pressA = true;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		_pressD = true;
		break;
	}
}

void Weapon::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (keycode)
	{
	
	case EventKeyboard::KeyCode::KEY_A:
		_pressA = false;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		_pressD = false;
		break;
	}
}



void Weapon::makeBullet()
{
	playerbullet1 = Sprite::create("bullet.png");
	playerbullet1->setAnchorPoint(Vec2(0, 0));
	
	if (!RIGHT)
		sign = -1;
	else if (RIGHT)
		sign = +1;
	playerbullet1->setPosition(player->getPositionX()+50 + sign*55, player->getPositionY() + 55);
	
	playerbullet1->setZOrder(5);

	auto movebullet = MoveBy::create(0.8, Vec2(sign * 1000 * (!_up), 1000 * _up));

	playerbullet1->runAction(movebullet);

	this->addChild(playerbullet1);
}

void Weapon::makeMachinegun()
{
	playerbullet1 = Sprite::create("machinegun1.png");
	playerbullet1->setScale(2);
	playerbullet1->setAnchorPoint(Vec2(0, 0));
	
	if (!RIGHT)
	{
		sign = -1;
		playerbullet1->setFlippedX(true);
		playerbullet1->setRotation(upPressedTime);
	}
	else if (RIGHT)
	{
		sign = +1;
		playerbullet1->setFlippedX(false);
		playerbullet1->setRotation(-upPressedTime);
	}

	playerbullet1->setPosition(player->getPositionX() + 50 + sign * 55, player->getPositionY() + 55);

	playerbullet1->setZOrder(5);

	auto moveMachinegunbullet = MoveBy::create(0.8, Vec2(sign * 1000 * cos(upPressedTime * 3.1415 / 180.0f), 1000 * sin(upPressedTime * 3.1415 / 180.0f)));

	playerbullet1->runAction(moveMachinegunbullet);

	this->addChild(playerbullet1);
}



void Weapon::update(float f)
{
	
}

