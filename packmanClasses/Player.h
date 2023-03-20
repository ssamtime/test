#pragma once

#include "cocos2d.h"
#include "stdafx.h"

enum PlayerDirection {RIGHT = 0, LEFT, UP, DOWN, LENGTH};
class Player : public cocos2d::Layer
{
public:
    Player();
    ~Player();

    static Player* create(cocos2d::Node* _listener, cocos2d::SEL_CallFunc _selector);
    virtual bool init(cocos2d::Node* _listener, cocos2d::SEL_CallFunc _selector);

    void onExit();
    void onEnter();

    // 키보드 콜백함수
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode,
        cocos2d::Event* event);
    void onKeyRelease(cocos2d::EventKeyboard::KeyCode keycode,
        cocos2d::Event* event);

    void SetMoveEventData();
    void update(float f);

    cocos2d::Node* _listener;
    cocos2d::SEL_CallFunc _selector;

    // 플레이어 이미지
    cocos2d::Sprite* _player;
    // 타일맵에서의 포지션
    Coordinate _mapPos;

    // 플레이어의 스피드
    float _speed = 100;

private:
    cocos2d::EventListenerKeyboard* _keyboardListener;

    // 방향에 따른 애니메이션 배열
    cocos2d::Animation* _animPlayer[PlayerDirection::LENGTH];
    cocos2d::Animate* _animate;

    PlayerDirection _dirState;
    bool _curDir[PlayerDirection::LENGTH];

    bool isMoving = false;

    void SetBoolDirection(PlayerDirection dir);
};
