#include "Weapon.h"
#include "Player.h"

USING_NS_CC;

cocos2d::Sprite* player;
bool _left;
bool _right;
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



void Weapon::makeBullet()
{
	playerbullet1 = Sprite::create("bullet.png");
	playerbullet1->setAnchorPoint(Vec2(0, 0));
	
	if (_left)
		sign = -1;
	else if (_right)
		sign = +1;
	playerbullet1->setPosition(player->getPositionX()+50 + sign*55, player->getPositionY() + 55);
	
	playerbullet1->setZOrder(5);
	moveBullet();

	this->addChild(playerbullet1);
}

void Weapon::moveBullet()
{
	
	if (_left)
		sign = -1;
	else if (_right)
		sign = +1;
	auto movebullet = MoveBy::create(0.8, Vec2(sign*1000 * cos(upPressedTime * 3.1415 / 180.0f), 1000*sin(upPressedTime*3.1415/180.0f)));
	
	playerbullet1->runAction(movebullet);
	
}

void Weapon::update(float f)
{

}

