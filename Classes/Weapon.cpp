
#include "Player.h"
#include <extensions/cocos-ext.h>
#include <cocos-ext.h>
USING_NS_CC;
USING_NS_CC_EXT;

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
	playerbullet1->setPosition(player->getPositionX()  , player->getPositionY() -1000);
	playerbullet1->setZOrder(5);
	this->addChild(playerbullet1);

	machinegunCapsule = Sprite::create("machinegunCapsule.png");
	machinegunCapsule->setAnchorPoint(Vec2(0, 0));
	machinegunCapsule->setPosition(Vec2(1600, 100));
	machinegunCapsule->setZOrder(6);
	machinegunCapsule->setScale(3);
	this->addChild(machinegunCapsule);

	isMachinegun = false;

	bomb = Sprite::create("bombhollow.png");
	bomb->setAnchorPoint(Vec2(0, 0));
	bomb->setPosition(player->getPositionX(), player->getPositionY() -1000);
	bomb->setZOrder(5);
	this->addChild(bomb);

	

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
			//makeMachinegun();
			//auto delay = DelayTime::create(2.0f); // 2초 지연
			//auto func = CallFunc::create(CC_CALLBACK_0(Weapon::makeMachinegun(), this)); // 함수 호출
			//this->runAction(Sequence::create(delay, func, nullptr)); // 시퀀스로 실행
		}
		_pressA = true;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		makebomb();
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
	playerbullet1->setZOrder(5);

	if (!RIGHT)
		sign = -1;
	else if (RIGHT)
		sign = +1;
	playerbullet1->setPosition(player->getPositionX()+50 + sign*55, player->getPositionY() + 55);

	auto movebullet = MoveBy::create(0.8, Vec2(sign * 1000 * (!_up), 1000 * _up));
	playerbullet1->runAction(movebullet);

	this->addChild(playerbullet1);
}

void Weapon::makeMachinegun()
{
	
	if (!RIGHT)
	{
		sign = -1;
		playerbullet1 = Sprite::create("machinegun2.png");
		playerbullet1->setScale(2);
		playerbullet1->setAnchorPoint(Vec2(1, 0));
		playerbullet1->setPosition(player->getPositionX() +45 + sign * 55, player->getPositionY() + 60);
		playerbullet1->setZOrder(5);
		playerbullet1->setRotation(upPressedTime);

		
	}
	else if (RIGHT)
	{
		sign = +1;
		playerbullet1 = Sprite::create("machinegun1.png");
		playerbullet1->setScale(2);
		playerbullet1->setAnchorPoint(Vec2(0, 0));
		playerbullet1->setPosition(player->getPositionX() + 85 + sign * 55, player->getPositionY() + 60);
		playerbullet1->setZOrder(5);
		playerbullet1->setRotation(-upPressedTime);
	}

	auto moveMachinegunbullet = MoveBy::create(0.8, Vec2(sign * 1000 * cos(upPressedTime * 3.1415 / 180.0f), 1000 * sin(upPressedTime * 3.1415 / 180.0f)));
	playerbullet1->runAction(moveMachinegunbullet);
	this->addChild(playerbullet1);
}

void Weapon::makebomb()
{
	if (!RIGHT)
		sign = -1;
	else if (RIGHT)
		sign = +1;
	bomb = Sprite::create("bomb1.png");
	bomb->setScale(2);
	bomb->setAnchorPoint(Vec2(0, 0));
	bomb->setPosition(player->getPositionX() + 50 + sign * 55, player->getPositionY() + 60);
	bomb->setZOrder(6);
	this->addChild(bomb);

	auto bombanimation = Animation::create();
	bombanimation->setDelayPerUnit(0.1);
	bombanimation->addSpriteFrameWithFile("bomb1.png");
	bombanimation->addSpriteFrameWithFile("bomb2.png");
	bombanimation->addSpriteFrameWithFile("bomb3.png");
	bombanimation->addSpriteFrameWithFile("bomb4.png");
	bombanimation->addSpriteFrameWithFile("bomb5.png");
	bombanimation->addSpriteFrameWithFile("bomb6.png");
	bombanimation->addSpriteFrameWithFile("bomb7.png");
	bombanimation->addSpriteFrameWithFile("bomb8.png");
	bombanimation->addSpriteFrameWithFile("bomb9.png");
	bombanimation->addSpriteFrameWithFile("bomb10.png");
	bombanimation->addSpriteFrameWithFile("bomb11.png");
	bombanimation->addSpriteFrameWithFile("bomb12.png");
	bombanimation->addSpriteFrameWithFile("bomb13.png");
	bombanimation->addSpriteFrameWithFile("bomb14.png");
	bombanimate = Animate::create(bombanimation);
	auto bombseq = Sequence::create(bombanimate, Hide::create(), nullptr);
	bomb->runAction(bombseq);


	bezier.controlPoint_1 = Vec2( 0,  150);
	bezier.controlPoint_2 = Vec2(sign*200,  150);
	bezier.endPosition = Vec2(sign*200,  -50);
	auto bezierby = BezierBy::create(1, bezier);
	bomb->runAction(bezierby);
	
}


void Weapon::update(float f)
{
		
}

