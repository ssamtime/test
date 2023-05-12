#pragma once

#include "cocos2d.h"
#include "GameScene.h"

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

    cocos2d::EventListenerKeyboard* _listener;
   
};

