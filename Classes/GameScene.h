#pragma once

#include "cocos2d.h"
#include "StartScene.h"
#include "Player.h"
#include "Weapon.h"
#include "Enemy.h"
#include "ChooseScene.h"

class GameScene : public cocos2d::Scene
{
public:

    static cocos2d::Scene* createScene();

    GameScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    cocos2d::Label* scorelabel;
    cocos2d::Label* guncountlabel;
    cocos2d::Label* bombcountlabel;

    void update(float f)override;
        
    cocos2d::Sprite* infinitysprite;
    

};

extern cocos2d::Sprite* background1;
extern cocos2d::Sprite* life;

extern int score;
extern int machinguncount;
extern int bombcount;
