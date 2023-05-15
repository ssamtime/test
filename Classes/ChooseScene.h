#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "StartScene.h"

class ChooseScene : public cocos2d::Scene
{
    
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(ChooseScene);

    void onEnter();
    void onExit();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void lightsprite();
    void characterlockin();
    void function2();

    void update(float f)override;

    cocos2d::EventListenerKeyboard* _listener;
   
    cocos2d::Sprite* player1picture;
    cocos2d::Sprite* player2picture;
    cocos2d::Sprite* player3picture;
    cocos2d::Sprite* player4picture;
    cocos2d::Sprite* p1light1;
    cocos2d::Sprite* p1light2;
    cocos2d::Sprite* p1light3;
    cocos2d::Sprite* p1light4;

    cocos2d::Animation* p1lightanimation;
    cocos2d::Animate* p1lightanimate;
    cocos2d::Action* p1lightanimateRepFoever1;

    cocos2d::Label* creditlabel;

    int soundId2;
    int soundId12;
    int number;
};

