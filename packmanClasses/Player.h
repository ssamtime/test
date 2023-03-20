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

    // Ű���� �ݹ��Լ�
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode,
        cocos2d::Event* event);
    void onKeyRelease(cocos2d::EventKeyboard::KeyCode keycode,
        cocos2d::Event* event);

    void SetMoveEventData();
    void update(float f);

    cocos2d::Node* _listener;
    cocos2d::SEL_CallFunc _selector;

    // �÷��̾� �̹���
    cocos2d::Sprite* _player;
    // Ÿ�ϸʿ����� ������
    Coordinate _mapPos;

    // �÷��̾��� ���ǵ�
    float _speed = 100;

private:
    cocos2d::EventListenerKeyboard* _keyboardListener;

    // ���⿡ ���� �ִϸ��̼� �迭
    cocos2d::Animation* _animPlayer[PlayerDirection::LENGTH];
    cocos2d::Animate* _animate;

    PlayerDirection _dirState;
    bool _curDir[PlayerDirection::LENGTH];

    bool isMoving = false;

    void SetBoolDirection(PlayerDirection dir);
};
