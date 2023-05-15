#pragma once

#include "cocos2d.h"
#include "GameScene.h"
#include "ChooseScene.h"
#include "audio/include/AudioEngine.h"

class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(StartScene);

    void onEnter();
    void onExit();
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);

    void update(float f)override;

    void showmessage();
    cocos2d::EventListenerKeyboard* _listener;
    bool isshown;

    int soundId;
    

    cocos2d::Label* creditlabel;
};
extern int credit;
