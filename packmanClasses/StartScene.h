#pragma once

#include "cocos2d.h"
#include "GameScene.h"

class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(StartScene);

    void doPushScene(Ref* pSender);
};

