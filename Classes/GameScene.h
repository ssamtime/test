#pragma once

#include "cocos2d.h"
#include "StartScene.h"
#include "Player.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    cocos2d::Layer* layer1;
    static cocos2d::Sprite* background1;

};

