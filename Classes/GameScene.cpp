#include "GameScene.h"
#include "GameManager.h"
#include "StartScene.h"

USING_NS_CC;
using namespace std;

Scene* GameScene::createScene()
{
    return GameScene::create();
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto wlayer = LayerColor::create(Color4B::WHITE);
    this->addChild(wlayer);

   
    return true;
}

void GameScene::GameManagerCallback()
{
    // 종료 루틴을 넣어준다.
    _director->getTextureCache()->removeUnusedTextures();

    auto pScene = StartScene::createScene();
    Director::getInstance()->replaceScene(pScene);

 
}
