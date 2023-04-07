#include "Player.h"

USING_NS_CC;

cocos2d::Sprite* background1;
cocos2d::Sprite* arabian1;
cocos2d::Sprite* arabian2;
cocos2d::Sprite* arabian3;

Player::Player()
{
}

Player::~Player()
{
}

bool Player::init()
{
    player = Sprite::create("Fio.png");
    player->setScale(3);
    player->setAnchorPoint(Vec2(0, 0));
    player->setPosition(Vec2(100, 100));
    player->setZOrder(5);
    this->addChild(player);

	_left = _right = _up = _down = false;
	upPressedTime = 0;


	this->scheduleUpdate();

	return true;
}

void Player::onEnter()
{
	Layer::onEnter();

	_listener = EventListenerKeyboard::create();

	//콜백함수 연결
	_listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	_listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener, this);
}

void Player::onExit()
{
	_eventDispatcher->removeEventListener(_listener);

	Layer::onExit();
}

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_left = true;
		
		player->setFlippedX(true);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_right = true;
		
		player->setFlippedX(false);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		jump();
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		_up = true;
		this->unschedule(schedule_selector(Player::discountUppressedTime));
		this->schedule(schedule_selector(Player::countUppressedTime), 0.1f);
		break;
	}
}

void Player::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		_left = false;
		
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_right = false;
		
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:

		_up = false;
		this->unschedule(schedule_selector(Player::countUppressedTime));
		this->schedule(schedule_selector(Player::discountUppressedTime), 0.1f);
		if (upPressedTime == 0)
			this->unschedule(schedule_selector(Player::discountUppressedTime));
		
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		_down = false;
		break;
	}
}

void Player::update(float f)
{
	if (_left)
	{
		if (player->getPositionX() < 0)
		{

		}
		else
		{
			player->setPositionX(player->getPositionX() - 10);
		}
		
	}
	if (_right)
	{
		float bgwidth = background1->getContentSize().width;
		float playerpositionx = background1->getPositionX();
		
		if (player->getPositionX() > 500 && background1->getPositionX() >  -bgwidth + 1100)
		{
			moveBackground();
			
		}
		
		else
		{
			if (player->getPositionX() > 800)
			{
				player->setPositionX(player->getPositionX() - 10);
			}
			player->setPositionX(player->getPositionX() + 10);
		}
		
	}
	
	if (arabian1->getBoundingBox().intersectsRect(player->getBoundingBox()) ||
		arabian2->getBoundingBox().intersectsRect(player->getBoundingBox()) ||
		arabian3->getBoundingBox().intersectsRect(player->getBoundingBox()) && isCollided)
	{
		playerDeath();
		
		isCollided = false;
	}
}

void Player::jump()
{
	if (player->getActionByTag(1)==0)
	{
		auto jump = MoveBy::create(0.3, Vec2(0, 100));
		auto reversejump = jump->reverse();
		auto sequence = Sequence::create(jump, reversejump, nullptr);
		sequence->setTag(1);
		player->runAction(sequence);
		
	}
}

void Player::moveBackground()
{
	background1->setPositionX(background1->getPositionX() - 10);
}


void Player::discountUppressedTime(float f)
{
	if (upPressedTime > 0)
	{
		upPressedTime -= 15;
	}
}

void Player::countUppressedTime(float f)
{
	if (upPressedTime < 90)
	{
		upPressedTime += 15;
	}
}

void Player::playerDeath()
{
	this->getEventDispatcher()->setEnabled(false);

	auto deathanimation = Animation::create();
	deathanimation->setDelayPerUnit(0.12);

	deathanimation->addSpriteFrameWithFile("playerdeath1.png");
	deathanimation->addSpriteFrameWithFile("playerdeath2.png");
	deathanimation->addSpriteFrameWithFile("playerdeath3.png");
	deathanimation->addSpriteFrameWithFile("playerdeath4.png");
	deathanimation->addSpriteFrameWithFile("playerdeath5.png");
	deathanimation->addSpriteFrameWithFile("playerdeath6.png");
	deathanimation->addSpriteFrameWithFile("playerdeath7.png");
	deathanimation->addSpriteFrameWithFile("playerdeath8.png");
	deathanimation->addSpriteFrameWithFile("playerdeath9.png");
	deathanimation->addSpriteFrameWithFile("playerdeath10.png");
	deathanimation->addSpriteFrameWithFile("playerdeath11.png");
	deathanimation->addSpriteFrameWithFile("playerdeath12.png");
	deathanimation->addSpriteFrameWithFile("playerdeath13.png");
	deathanimation->addSpriteFrameWithFile("playerdeath14.png");
	deathanimation->addSpriteFrameWithFile("playerdeath15.png");
	deathanimation->addSpriteFrameWithFile("playerdeath16.png");
	deathanimation->addSpriteFrameWithFile("playerdeath17.png");
	deathanimation->addSpriteFrameWithFile("playerdeath18.png");
	deathanimation->addSpriteFrameWithFile("playerdeath19.png");
	deathanimation->addSpriteFrameWithFile("playerdeath20.png");
	deathanimation->addSpriteFrameWithFile("playerdeath21.png");
	deathanimation->addSpriteFrameWithFile("playerdeath22.png");
	deathanimation->addSpriteFrameWithFile("playerdeath23.png");

	auto deathanimate = Animate::create(deathanimation);
	player->runAction(deathanimate);
	
	
}