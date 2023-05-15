#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "Enemy.h"
#include "Weapon.h"
#include "StartScene.h"

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

    void discountUppressedTime(float f);
    void countUppressedTime(float f);

    cocos2d::EventListenerKeyboard* _listener;

    cocos2d::Label* creditlabel;

    bool _down;

    bool isCollided1;
    bool isCollided2;
    bool isCollided3;
    bool isCollidedleftflame;
    bool isCollidedrightflame;
    bool iscollidedcapsule;

    bool playerAlive;
    void update(float f)override;
    
    void jump();
    void moveBackground();

    void playerDeath();
    void animationCallback();
    int soundId12;

    cocos2d::Animate* mergeanimate;
private:

};
extern cocos2d::Sprite* player;
extern bool _left;
extern bool _right;
extern bool RIGHT;
extern bool _up;
extern float upPressedTime;
