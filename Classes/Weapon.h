#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "Player.h"

class Weapon : public cocos2d::Layer
{
public:
    Weapon();
    ~Weapon();

    virtual bool init();

    CREATE_FUNC(Weapon);

    void onEnter();
    void onExit();

    //키보드 콜백함수
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

    
    cocos2d::EventListenerKeyboard* _listener;

    bool _pressA;
    bool _pressD;

    void update(float f)override;
    
    void makeBullet();
    void moveBullet();

    cocos2d::Sprite* bullet1;
 
private:

};
