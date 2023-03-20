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

    //// 팩맨의 기본 이동 방향 초기화
    //this->_dirState = PlayerDirection::LEFT;
    //this->SetBoolDirection(_dirState);

    //
    //auto sprite = Sprite::create("Player.png");

    //for (int i = 0; i < PlayerDirection::LENGTH; i++)
    //{
    //    // 애니메이션 초기화 1
    //    _animPlayer[i] = Animation::create();
    //    // init 이외에도 쓸것이기에 Ref's Count를 올려준다.
    //    _animPlayer[i]->retain();
    //}

    //// 애니메이션 초기화 2
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

    //// 애니메이트 초기화
    //_animate = Animate::create(_animPlayer[PlayerDirection::LEFT]);
    //// init 이외에도 쓸것이기에 Ref's Count를 올려준다.
    //_animate->retain();

    //auto rep = RepeatForever::create(_animate);
    //_player->runAction(rep);

    //// Layer 크기( == 충돌체 크기 )
    //this->setContentSize(Size(CELL_WIDTH / 2, CELL_HEIGHT / 2));

    //// update 실행
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

    // 콜백 함수 연결
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
    //// 벽에 충돌하는 위치라면 되돌리기 위함.
    //Coordinate originPos = this->_mapPos;
    //PlayerDirection _originDir = _dirState;

    //// 타일맵 기준으로 좌표가 이동된다.(이차원 배열 인덱스 기준)
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
    //    // 이동 방향 구하기
    //    Vec2 direction = pos - this->getPosition();
    //    // normalize로 벡터를 1로 만들어 방향만 남긴다.
    //    direction.normalize();

    //    isMoving = true;

    //    // 포지션은 기존 포지션 + (1장의 프레임 작동타임 * 방향 * 스피드)
    //    this->setPosition(this->getPosition() + (f * direction * this->_speed));
    //}
    //else
    //    isMoving = false;
}

void Player::SetBoolDirection(PlayerDirection dir)
{
    for (int i = 0; i < PlayerDirection::LENGTH; i++)
    {
        // 처음엔 무조건 false로 초기화
        _curDir[i] = false;
    }

    _curDir[dir] = true;
}
