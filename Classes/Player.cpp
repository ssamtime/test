#include "Player.h"
#include "GameManager.h"

USING_NS_CC;

Player::Player()
{
}

Player::~Player()
{
}

bool Player::init(cocos2d::Node* _listener, cocos2d::SEL_CallFunc _selector)
{
    //this->_listener = _listener;
    //this->_selector = _selector;

    //// �Ѹ��� �⺻ �̵� ���� �ʱ�ȭ
    //this->_dirState = PlayerDirection::LEFT;
    //this->SetBoolDirection(_dirState);

    //
    //auto sprite = Sprite::create("Player.png");

    //for (int i = 0; i < PlayerDirection::LENGTH; i++)
    //{
    //    // �ִϸ��̼� �ʱ�ȭ 1
    //    _animPlayer[i] = Animation::create();
    //    // init �̿ܿ��� �����̱⿡ Ref's Count�� �÷��ش�.
    //    _animPlayer[i]->retain();
    //}

    //// �ִϸ��̼� �ʱ�ȭ 2
    //for (int i = 0; i < 48; i++)
    //{
    //    int column = i % 12;
    //    int row = i / 12;

    //    _animPlayer[row]->addSpriteFrameWithTexture(
    //        texture,
    //        Rect(column * 26, row * 26, 26, 26));
    //    _animPlayer[row]->setDelayPerUnit(0.05f);
    //}

    //_player = Sprite::createWithTexture(
    //    texture, Rect(0, 0, 26, 26));
    //
    //_player->setPosition(0, 0);
    //_player->setAnchorPoint(Vec2(0, 0));
    //_player->setScale(0.55f);
    //this->addChild(_player);

    //// �ִϸ���Ʈ �ʱ�ȭ
    //_animate = Animate::create(_animPlayer[PlayerDirection::LEFT]);
    //// init �̿ܿ��� �����̱⿡ Ref's Count�� �÷��ش�.
    //_animate->retain();

    //auto rep = RepeatForever::create(_animate);
    //_player->runAction(rep);

    //// Layer ũ��( == �浹ü ũ�� )
    //this->setContentSize(Size(CELL_WIDTH / 2, CELL_HEIGHT / 2));

    //// update ����
    //this->scheduleUpdate();

    return true;
}

void Player::onExit()
{
    _eventDispatcher->removeEventListener(_keyboardListener);

    Layer::onExit();
}

void Player::onEnter()
{
    Layer::onEnter();

    _keyboardListener = EventListenerKeyboard::create();

    // �ݹ� �Լ� ����
    _keyboardListener->onKeyPressed =
        CC_CALLBACK_2(Player::onKeyPressed, this);
    _keyboardListener->onKeyReleased =
        CC_CALLBACK_2(Player::onKeyReleased, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(_keyboardListener, this);
}

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
    switch (keycode)
    {
    case EventKeyboard::KeyCode::KEY_A:
        SetBoolDirection(PlayerDirection::LEFT);
        break;
    case EventKeyboard::KeyCode::KEY_D:
        SetBoolDirection(PlayerDirection::RIGHT);
        break;
    case EventKeyboard::KeyCode::KEY_W:
        SetBoolDirection(PlayerDirection::UP);
        break;
    case EventKeyboard::KeyCode::KEY_S:
        SetBoolDirection(PlayerDirection::DOWN);
        break;
    }
}

void Player::onKeyRelease(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
}

void Player::SetMoveEventData()
{
    //// ���� �浹�ϴ� ��ġ��� �ǵ����� ����.
    //Coordinate originPos = this->_mapPos;
    //PlayerDirection _originDir = _dirState;

    //// Ÿ�ϸ� �������� ��ǥ�� �̵��ȴ�.(������ �迭 �ε��� ����)
    //if (_curDir[PlayerDirection::LEFT])
    //{
    //    this->_mapPos += Coordinate(-1, 0);
    //    _dirState = PlayerDirection::LEFT;
    //}
    //else if (_curDir[PlayerDirection::RIGHT])
    //{
    //    this->_mapPos += Coordinate(1, 0);
    //    _dirState = PlayerDirection::RIGHT;
    //}
    //else if (_curDir[PlayerDirection::UP])
    //{
    //    this->_mapPos += Coordinate(0, -1);
    //    _dirState = PlayerDirection::UP;
    //}
    //else if (_curDir[PlayerDirection::DOWN])
    //{
    //    this->_mapPos += Coordinate(0, 1);
    //    _dirState = PlayerDirection::DOWN;
    //}

}

void Player::update(float f)
{
    //if (isMoving == false)
    //    SetMoveEventData();

    //if (this->getPosition().getDistance(pos) > 1.0f)
    //{
    //    // �̵� ���� ���ϱ�
    //    Vec2 direction = pos - this->getPosition();
    //    // normalize�� ���͸� 1�� ����� ���⸸ �����.
    //    direction.normalize();

    //    isMoving = true;

    //    // �������� ���� ������ + (1���� ������ �۵�Ÿ�� * ���� * ���ǵ�)
    //    this->setPosition(this->getPosition() + (f * direction * this->_speed));
    //}
    //else
    //    isMoving = false;
}

void Player::SetBoolDirection(PlayerDirection dir)
{
    for (int i = 0; i < PlayerDirection::LENGTH; i++)
    {
        // ó���� ������ false�� �ʱ�ȭ
        _curDir[i] = false;
    }

    _curDir[dir] = true;
}
