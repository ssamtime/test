#include "Weapon.h"
#include "Player.h"

USING_NS_CC;

cocos2d::Sprite* player;
bool isLeftPressed;
bool isRightPressed;
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
		makeBullet();
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

void Weapon::update(float f)
{
	
	if (_pressA)
	{
		
	}
	if (_pressD)
	{
		
	}
}

void Weapon::makeBullet()
{
	bullet1 = Sprite::create("bullet.png");
	bullet1->setAnchorPoint(Vec2(0, 0));
	bullet1->setPosition(player->getPositionX() + 100, player->getPositionY()+50);
	bullet1->setZOrder(5);
	moveBullet();

	this->addChild(bullet1);
}

void Weapon::moveBullet()
{
	
	if (isLeftPressed)
		sign = -1;
	else if (isRightPressed)
		sign = +1;
	auto movebullet = MoveBy::create(1, Vec2(sign*1000 * cos(upPressedTime * 3.1415 / 180.0f), 1000*sin(upPressedTime*3.1415/180.0f)));
	
	bullet1->runAction(movebullet);
	
}



