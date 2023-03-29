#include "Player.h"

USING_NS_CC;

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
		isLeftPressed = true;
		if(isRightPressed)
			player->setFlippedX(true);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		_right = true;
		isRightPressed = true;
		if (isLeftPressed)
			player->setFlippedX(false);
		break;
	case EventKeyboard::KeyCode::KEY_S:
		jump();
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		_down = true;
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
		if (player->getPositionX() > 500)
		{
			moveBackground();
		}
		else
		{
			player->setPositionX(player->getPositionX() - 10);
		}
		
	}
	if (_right)
	{
		player->setPositionX(player->getPositionX() + 10);
	}
	if (_up)
	{
		player->setPositionY(player->getPositionY() + 10);
	}
	if (_down)
	{
		
	}
}

void Player::jump()
{
	auto jump = MoveBy::create(0.3, Vec2(0, 100));
	auto reversejump = jump->reverse();
	auto sequence = Sequence::create(jump, reversejump, nullptr);
	
	player->runAction(sequence);
}

void Player::moveBackground()
{
	GameScene::background1->setPositionX(GameScene::background1->getPositionX() - 10);
}


