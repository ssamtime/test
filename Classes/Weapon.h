#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "Player.h"
#include "Weapon.h"

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

    

    int sign;

    void update(float f)override;
    void makeBullet();
    void makeMachinegun();
    void makebomb();
   
    cocos2d::Animate* bombanimate;
 
   /* cocos2d::Sprite* bomb;*/

    cocos2d::ccBezierConfig bezier;

private:

};

extern cocos2d::Sprite* playerbullet1;
extern cocos2d::Sprite* playerbullet2;
extern cocos2d::Sprite* machinegunCapsule;
extern cocos2d::Sprite* bomb;
extern bool isMachinegun;
extern bool _pressA;
extern bool _pressD;