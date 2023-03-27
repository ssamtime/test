#pragma once

#include "cocos2d.h"

enum PlayerDirection {RIGHT = 0, LEFT, UP, DOWN, LENGTH};

class Player : public cocos2d::Layer
{
public:
    Player();
    ~Player();

    virtual bool init();

    CREATE_FUNC(Player);


    void onEnter();
    void onExit();

    //키보드 콜백함수
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

private:
    cocos2d::Sprite* player;
    cocos2d::EventListenerKeyboard* _listener;

    bool _left;
    bool _right;
    bool _up;
    bool _down;

    bool isLeftPressed;
    bool isRightPressed;

    void update(float f)override;
    
    void jump();
    

 
};
